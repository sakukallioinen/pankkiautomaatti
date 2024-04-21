#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

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

    //void setIdAccount(const QString &newIdAccount);

    void setIdCard(const QString &newIdCard);


private slots:

    void handleAccountIdResponse(QNetworkReply *reply);
    void getSaldoSlot (QNetworkReply *reply);
    void on_ActionsPushButton_clicked();
    void on_getMoneyPushButton_clicked();
    void on_balancePushButton_clicked();
    void on_logOutPushButton_clicked();
    void on_chooseAccountPushButton_clicked();

    void requestBalance(const QString &accountIdString);

private:
    QNetworkAccessManager *saldoManager;
    QNetworkReply *reply;
    QByteArray webToken;
    QByteArray response_data;
    QString idCard;



    Ui::paasivu *ui;
    void asetaTeksti();
};

#endif // PAASIVU_H
