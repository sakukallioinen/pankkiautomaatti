#include "paasivu.h"
#include "saldo.h"
#include "tilinvalinta.h"
#include "ui_paasivu.h"
#include "otto.h"
#include "tapahtumat.h"

paasivu::paasivu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::paasivu)
{
    ui->setupUi(this);

    connect(ui->getMoneyPushButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->logOutPushButton, SIGNAL(clicked()), this, SLOT(on_logoutPushButton_clicked()));
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
    ObjectOtto->show();
}

void paasivu::on_balancePushButton_clicked()
{
    Saldo *objectSaldo = new Saldo(this);
    objectSaldo->show();

    QString site_url = "http://localhost:3000/account";
    QNetworkRequest request(site_url);

    //WEBTOKEN ALKU
    QByteArray myToken = "Bearer +webToken";
    request.setRawHeader(QByteArray("Authorization"), myToken);
    //WEBTOKEN LOPPU

    saldoManager = new QNetworkAccessManager(this);
    connect(saldoManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getSaldoSlot(QNetworkReply*)));

    reply = saldoManager->get(request);
}

void paasivu::on_logoutPushButton_clicked()
{
    this->close();
}

void paasivu::on_chooseAccountPushButton_clicked()
{
    Tilinvalinta *objectTilinValinta = new Tilinvalinta(this);
    objectTilinValinta->show();
}

void paasivu::asetaTeksti()
{
    ui->label->setText("Tervetuloa");
}

void paasivu::getSaldoSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug() << "DATA : " + response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString balance;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        balance += (json_obj["balance"].toString()) + "\r\n" + json_obj["creditLimit"].toString();
    }

    Saldo *saldoWindow = new Saldo(this);
    saldoWindow->updateBalance(balance);
    saldoWindow->show();

    reply->deleteLater();
    saldoManager->deleteLater();
}
