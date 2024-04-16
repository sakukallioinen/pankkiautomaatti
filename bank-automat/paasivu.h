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

private slots:

    void getSaldoSlot (QNetworkReply *reply);
    void on_ActionsPushButton_clicked();
    void on_getMoneyPushButton_clicked();
    void on_balancePushButton_clicked();
    void on_logoutPushButton_clicked();
    void on_chooseAccountPushButton_clicked();

private:
    QNetworkAccessManager *saldoManager;
    QNetworkReply *reply;
    QByteArray response_data;

    Ui::paasivu *ui;
    void asetaTeksti();
};

#endif // PAASIVU_H
