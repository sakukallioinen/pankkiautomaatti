#include "environment.h"
#include "otto.h"
#include "muusumma.h"
#include "ui_otto.h"
#include "AccountManager.h"
#include <QInputDialog>
#include <QMessageBox>

otto::otto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otto)
{
    ui->setupUi(this);
    connect(ui->pushButtonAlkuun, SIGNAL(clicked()), this, SLOT(close()));
}

otto::~otto()
{
    delete ui;
}

void otto::on_pushButton20_clicked()
{
    updateBalance(20);
}

void otto::on_pushButton40_clicked()
{
    updateBalance(40);
}

void otto::on_pushButton60_clicked()
{
    updateBalance(60);
}

void otto::on_pushButton90_clicked()
{
    updateBalance(90);
}

void otto::on_pushButton140_clicked()
{
    updateBalance(140);
}

void otto::on_pushButton240_clicked()
{
    updateBalance(240);
}

void otto::on_pushButtonMuuSumma_clicked()
{
    MuuSumma *objectMuuSumma = new MuuSumma(this);
    connect(objectMuuSumma, SIGNAL(pinEntered(int)), this, SLOT(updateBalance(int)));
    objectMuuSumma->show();
}

void otto::updateBalance(int amount)
{
    QString accountId = AccountManager::getInstance().getAccountId();
    if (accountId.isEmpty()) {
        qDebug() << "Error: Account ID is empty";
        return;
    }

    QString site_url = Environment::getBaseUrl() + "/debitwithdrawal";
    QNetworkRequest request(site_url);

    QByteArray myToken = "Bearer " + webToken;
    request.setRawHeader(QByteArray("Authorization"), myToken);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateBalanceSlot(QNetworkReply*)));

    QJsonObject jsonObj;
    jsonObj.insert("idaccount", accountId);
    jsonObj.insert("amount", amount);

    manager->post(request, QJsonDocument(jsonObj).toJson());
}


void otto::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}


void otto::updateBalanceSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug() << "Update Balance Response: " << response_data;
    reply->deleteLater();
    manager->deleteLater();
}

void otto::on_pushButtonAlkuun_clicked()
{
    this->close();

}
