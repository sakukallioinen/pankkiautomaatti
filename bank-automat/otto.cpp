#include "environment.h"
#include "otto.h"
#include "ui_otto.h"
#include "AccountManager.h"

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
    // Tässä voit antaa käyttäjän syöttää haluamansa summan ja lähettää sen tietokantaan
    int muuSumma = 0; // Esimerkki, käytä oikeaa arvoa
    updateBalance(muuSumma);
}

void otto::updateBalance(int amount)
{
    // Ennen kuin kutsut tietokantaproseduuria, sinun täytyy varmistaa, että sinulla on ensimmäisen tilin tunniste saatavilla
    QString accountId = AccountManager::getInstance().getAccountId();
    if (accountId.isEmpty()) {
        qDebug() << "Error: Account ID is empty";
        return;
    }

    // Tee kutsu tietokantaproseduuriin debit_withdrawal
    QString site_url = Environment::getBaseUrl() + "/debitwithdrawal";
    QNetworkRequest request(site_url);

    // Aseta Web Token headeriin
    QByteArray myToken = "Bearer " + webToken;
    request.setRawHeader(QByteArray("Authorization"), myToken);

    // Aseta otsikko sisällön tyypille
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Luo QNetworkAccessManager instanssi tai käytä olemassaolevaa, jos se on jo luotu
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateBalanceSlot(QNetworkReply*)));

    // Luo JSON
    QJsonObject jsonObj;
    jsonObj.insert("idaccount", accountId);
    jsonObj.insert("amount", amount);

    // Lähetä pyyntö POST-metodilla
    manager->post(request, QJsonDocument(jsonObj).toJson());
}


void otto::sendUpdatedBalance(int newBalance)
{
    QJsonObject jsonObj;
    jsonObj.insert("balance", newBalance);

    // Muodosta URL päivitetyn saldon lähettämiseksi palvelimelle
    QString site_url = Environment::getBaseUrl() + "/account/" + AccountManager::getInstance().getAccountId();
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Aseta Web Token headeriin
    QByteArray myToken = "Bearer " + webToken;
    request.setRawHeader(QByteArray("Authorization"), myToken);

    // Luo QNetworkAccessManager instanssi tai käytä olemassaolevaa, jos se on jo luotu
    putBalance = new QNetworkAccessManager(this);

    connect(putBalance, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateBalanceSlot(QNetworkReply*)));

    // Lähetä päivitetty saldo palvelimelle
    putBalance->put(request, QJsonDocument(jsonObj).toJson());
}

void otto::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

/*void otto::setIdAccount(const QString &newIdAccount)
{
    idAccount = newIdAccount;
    qDebug() << "idAccount: " << newIdAccount;
}
*/
void otto::getBalanceSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    reply->deleteLater();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    int currentBalance = json_obj["balance"].toInt();
    int newBalance = currentBalance - this ->amount;

    sendUpdatedBalance(newBalance);

    getBalanceManager->deleteLater();
    /*QJsonObject jsonObj;
    jsonObj.insert("balance", newBalance);

    QString site_url = "http://localhost:3000/account/1";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken = "Bearer " + webToken;
    request.setRawHeader(QByteArray("Authorization"), myToken);
    //WEBTOKEN LOPPU

    putBalance = new QNetworkAccessManager(this);
    connect(putBalance, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateBalanceSlot(QNetworkReply*)));

    reply = putBalance->put(request, QJsonDocument(jsonObj).toJson());
    this->close();*/
}

void otto::updateBalanceSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug() << "Update Balance Response: " << response_data;
    reply->deleteLater();
    putBalance->deleteLater();
}

void otto::on_pushButtonAlkuun_clicked()
{
    this->close();

}
