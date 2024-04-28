#include "accountmanager.h"
#include "environment.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditCardNum->setFocus();
    pinInterface = new PinInterface(this);
    connect(pinInterface, SIGNAL(pinEntered(QString)), this, SLOT(pinHandlerSlot(QString)));

    rfidReader = new rfidreader(pinInterface, this);
    connect(rfidReader, &rfidreader::cardRead, this, &MainWindow::handleCardRead);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCardReader_clicked()
{
    QString cardID=ui->lineEditCardNum->text();
    QJsonObject jsonObj;
    jsonObj.insert("idcard", cardID);

    QString site_url=Environment::getBaseUrl()+"/login/checkcard";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    checkCardManager = new QNetworkAccessManager(this);
    connect(checkCardManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(checkCardSlot(QNetworkReply*)));

    reply = checkCardManager->post(request, QJsonDocument(jsonObj).toJson());

}

void MainWindow::pinHandlerSlot(QString s)
{
    QString pinCode = s;
    QString cardID=ui->lineEditCardNum->text();
    QJsonObject jsonObj;
    jsonObj.insert("pin", pinCode);
    jsonObj.insert("idcard", cardID);

    QString site_url=Environment::getBaseUrl()+"/login/checkpin";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    checkPinManager = new QNetworkAccessManager(this);
    connect(checkPinManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(checkPinSlot(QNetworkReply*)));

    reply = checkPinManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::checkCardSlot(QNetworkReply *reply)
{
        response_data = reply->readAll();
        //qDebug() << response_data;
        QMessageBox msgBox;
        if(response_data == "-4078") {
            msgBox.setText("Virhe tietokantayhteydessä");
            msgBox.exec();
        }
        else{
            if(response_data!="false"){
                //kortti ok
                pinInterface->open();
            }
            else{
                msgBox.setText("Kortti hylätty");
                msgBox.exec();
            }
        }
        reply->deleteLater();
        checkCardManager->deleteLater();
}

void MainWindow::checkPinSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();

    //qDebug() << response_data;
    if (response_data != "false")
    {
        // Kirjautuminen onnistui
        ui->label->setText("PIN hyväksytty");

        // Tallennetaan webToken
        QString webToken = response_data;
        //qDebug() << "WebToken: " << webToken;

        // Hae Account ID erillisellä pyynnöllä
        fetchAccountId(webToken);
        paasivu *objectPaasivu = new paasivu();
        objectPaasivu->setWebToken(response_data);
        objectPaasivu->show();
        this->close();
    }
    else
    {
        ui->label->setText("Invalid PIN");
    }
    reply->deleteLater();
    checkPinManager->deleteLater();
}

void MainWindow::fetchAccountId(const QString &webToken)
{
    QString card = ui->lineEditCardNum->text();
    QString site_url = Environment::getBaseUrl() + "/cardaccount/"+card;  // Oletetaan että tämä on oikea endpoint
    QNetworkRequest request(site_url);

    request.setRawHeader("Authorization", ("Bearer " + webToken).toUtf8());


    accountIdManager = new QNetworkAccessManager(this);
    connect(accountIdManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleAccountIdResponse(QNetworkReply*)));


    accountIdManager->get(request);
}

void MainWindow::handleAccountIdResponse(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QJsonObject jsonObject = json_array[0].toObject();

    int accountId = jsonObject["idAccount"].toInt();
    QString accountIdString = QString::number(accountId);
    if (!accountIdString.isEmpty())
    {
        AccountManager::getInstance().setAccountId(accountIdString);

    }
    else
    {
        qDebug() << "Failed to retrieve Account ID";
        // Käsittele tilanne, jossa Account ID:tä ei saada
    }
    reply->deleteLater();
    accountIdManager->deleteLater();
}

void MainWindow::handleCardRead(QString cardID)
{
    ui->lineEditCardNum->setText(cardID);
}




