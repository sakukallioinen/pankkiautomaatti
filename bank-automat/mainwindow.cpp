#include "environment.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pinInterface = new PinInterface(this);
    connect(pinInterface, SIGNAL(pinEntered(QString)), this, SLOT(pinHandlerSlot(QString)));
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
        qDebug() << response_data;
        QMessageBox msgBox;
        if(response_data == "-4078") {
            msgBox.setText("Virhe tietokantayhteydessä");
            msgBox.exec();
        }
        else{
            if(response_data!="false"){
                //kirjautuminen onnistui
                pinInterface->open();
            }
            else{
                msgBox.setText("Kortti hylätty");
                msgBox.exec();
            }
        }
}

void MainWindow::checkPinSlot(QNetworkReply *reply)
{
        response_data = reply->readAll();

        qDebug() << response_data;
        if (response_data != "false")
        {
            ui->label->setText("PIN hyväksytty");
            paasivu *objectPaasivu = new paasivu(this);
            objectPaasivu->show();
        }
        else
        {
            ui->label->setText("Invalid PIN");
        }
}





