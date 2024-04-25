#include "paasivu.h"
#include "saldo.h"
#include "tilinvalinta.h"
#include "ui_paasivu.h"
#include "otto.h"
#include "tapahtumat.h"
#include "environment.h"
#include "AccountManager.h"

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
    tapahtumat *objectTapahtumat = new tapahtumat(this);
    objectTapahtumat->show();
}

void paasivu::on_getMoneyPushButton_clicked()
{
    otto *ObjectOtto = new otto(this);
    ObjectOtto->setWebToken(webToken);
    ObjectOtto->show();
}


void paasivu::on_balancePushButton_clicked(){

    requestBalance();
    //qDebug()<<webToken;
}

void paasivu::on_logOutPushButton_clicked()
{
    this->close();
}

void paasivu::on_chooseAccountPushButton_clicked()
{
    Tilinvalinta *objectTilinValinta = new Tilinvalinta(this);
    objectTilinValinta->show();
}

void paasivu::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    qDebug() << "WebToken: " << webToken;
}


void paasivu::requestBalance()
{
    /*QString site_url = Environment::getBaseUrl() + "/account/" + accountIdString;  // Oletetaan että API endpoint on /accountBalance/
    QNetworkRequest request(site_url);

    QByteArray myToken = "Bearer " + webToken;
    request.setRawHeader("Authorization", myToken);

    saldoManager = new QNetworkAccessManager(this);
    connect(saldoManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getSaldoSlot(QNetworkReply*)));

    saldoManager->get(request);*/
    QString site_url = Environment::getBaseUrl() + "/account/" + AccountManager::getInstance().getAccountId();
    //qDebug()<<AccountManager::getInstance().getAccountId();
    QNetworkRequest request(site_url);
    QByteArray myToken = "Bearer " + webToken;
    //qDebug() << "WebToken: " << webToken;
    request.setRawHeader("Authorization", myToken);

    saldoManager = new QNetworkAccessManager(this);
    connect(saldoManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getSaldoSlot(QNetworkReply*)));

    saldoManager->get(request);
}

/*void paasivu::handleAccountIdResponse(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    //qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    if (!json_array.isEmpty())
    {
        QJsonObject json_obj = json_array[0].toObject();
        int accountId = json_obj["idAccount"].toInt();
        accountIdString = QString::number(accountId);
        //qDebug()<<"Account ID: " + accountIdString;

        requestBalance(accountIdString);
    }
    else
    {
        qDebug()<<"Error: Empty JSON array";
    }

    //QString accountIdString = QString::number(accountId); // Oletetaan että palautuu muodossa {"accountId": "12345"}

    // Nyt kun meillä on account ID, pyydetään saldoa
   //requestBalance(accountIdString);
}*/



void paasivu::asetaTeksti()
{
    ui->label->setText("Tervetuloa");
}

/*void paasivu::fetchAccountId(const QString &webToken)
{
    QString site_url = Environment::getBaseUrl() + "/cardaccount/" + idCard;
    QNetworkRequest request(site_url);
    request.setRawHeader("Authorization", ("Bearer " + webToken).toUtf8());

    accountIdManager = new QNetworkAccessManager(this);
    connect(accountIdManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleAccountIdResponse(QNetworkReply*)));

    accountIdManager->get(request);
}*/

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
