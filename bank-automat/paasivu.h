#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "accountmanager.h"

namespace Ui {
class paasivu;
}

class paasivu : public QDialog
{
    Q_OBJECT

public:
    explicit paasivu(QWidget *parent = nullptr);
    ~paasivu();





    void setWebToken(const QByteArray &newWebToken);

private slots:

    //void handleAccountIdResponse(QNetworkReply *reply);
    void getSaldoSlot (QNetworkReply *reply);
    void on_ActionsPushButton_clicked();
    void on_getMoneyPushButton_clicked();
    void on_balancePushButton_clicked();
    void on_logOutPushButton_clicked();
    void on_chooseAccountPushButton_clicked();


private:
    QNetworkAccessManager *saldoManager;
    QNetworkAccessManager *accountIdManager;
    QNetworkReply *reply;
    QByteArray webToken;
    QByteArray response_data;
    QString idCard;
    QString accountIdString;



    Ui::paasivu *ui;
    void asetaTeksti();
    //void fetchAccountId(const QString &webToken);
    void requestBalance();
};

#endif // PAASIVU_H
