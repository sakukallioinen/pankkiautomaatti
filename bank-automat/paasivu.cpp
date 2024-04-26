#include "paasivu.h"
#include "saldo.h"
#include "tilinvalinta.h"
#include "ui_paasivu.h"
#include "otto.h"
#include "tapahtumat.h"
#include "environment.h"
#include "AccountManager.h"
#include "mainwindow.h"

#include <QListWidgetItem>

paasivu::paasivu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::paasivu)
{
    ui->setupUi(this);

    connect(ui->getMoneyPushButton, SIGNAL(Clicked()), this, SLOT(close()));

}
paasivu::~paasivu()
{
    delete ui;
}


void paasivu::on_ActionsPushButton_clicked()
{
    requestTransactions();
}

void paasivu::on_getMoneyPushButton_clicked()
{
    otto *ObjectOtto = new otto(this);
    ObjectOtto->setWebToken(webToken);
    ObjectOtto->show();
}


void paasivu::on_balancePushButton_clicked(){

    requestBalance();
}

void paasivu::on_logOutPushButton_clicked()
{
    MainWindow *objectMainWindow = new MainWindow();
    objectMainWindow->show();
    delete this;
}

void paasivu::on_chooseAccountPushButton_clicked()
{
    Tilinvalinta *objectTilinValinta = new Tilinvalinta(this);
    objectTilinValinta->show();
}

void paasivu::getTransactionsSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    qDebug() << "DATA : " << response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString transaction ="TransactionID | AccountID | Tapahtuma | Määrä | Aika \r";
    tapahtumat *objectTapahtumat = new tapahtumat(this);
    int startIndex = qMax(0, json_array.size() - 5);
    for (int i = startIndex; i < json_array.size(); i++){
        QJsonObject json_obj = json_array[i].toObject();
        transaction+=QString::number(json_obj["idtransaction"].toInt())+" | ";
        transaction+=QString::number(json_obj["idAccount"].toInt())+" | ";
        transaction+=json_obj["withdraw"].toString()+" | ";
        transaction+=QString::number(json_obj["amount"].toInt())+" | ";
        transaction+=json_obj["date"].toString()+"\r";
    }
    objectTapahtumat->setTapahtumatString(transaction);
    objectTapahtumat->show();
    /*if(!json_array.isEmpty())
    {
        int startIndex = qMax(0, json_array.size() - 5);
        for (int i = startIndex; i < json_array.size(); i++)
        {
            QJsonObject json_obj = json_array[i].toObject();
            QListWidgetItem *item = new QListWidgetItem(json_obj["amount"].toString());
            tapahtumat *objectTapahtumat = new tapahtumat(this);
        }
    }
    else
    {
        qDebug() << "No transactions found";
    }*/
}

void paasivu::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    qDebug() << "WebToken: " << webToken;
}


void paasivu::requestBalance()
{

    QString site_url = Environment::getBaseUrl() + "/account/" + AccountManager::getInstance().getAccountId();
    QNetworkRequest request(site_url);
    QByteArray myToken = "Bearer " + webToken;
    request.setRawHeader("Authorization", myToken);

    saldoManager = new QNetworkAccessManager(this);
    connect(saldoManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getSaldoSlot(QNetworkReply*)));

    saldoManager->get(request);
}

void paasivu::requestTransactions()
{
    QString site_url = Environment::getBaseUrl() + "/transaction/" + AccountManager::getInstance().getAccountId();
    QNetworkRequest request(site_url);
    QByteArray myToken = "Bearer " + webToken;
    request.setRawHeader("Authorization", myToken);

    transactionManager = new QNetworkAccessManager(this);
    connect(transactionManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getTransactionsSlot(QNetworkReply*)));

    transactionManager->get(request);
}




void paasivu::asetaTeksti()
{
    ui->label->setText("Tervetuloa");
}



void paasivu::getSaldoSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    qDebug() << "DATA : " << response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();

    if(!json_array.isEmpty())
    {
        QJsonObject json_obj = json_array[0].toObject();
        Saldo *objectSaldo = new Saldo(this);
        objectSaldo->setBalance(json_obj["balance"].toString());
        objectSaldo->setCredit(json_obj["creditLimit"].toString());

        objectSaldo->show();

    }
    else
    {
        qDebug() << "Error: Empty JSON array";
    }
    reply->deleteLater();
    saldoManager->deleteLater();
}
