#ifndef OTTO_H
#define OTTO_H

#include <QDialog>
#include "paasivu.h"

namespace Ui {
class otto;
}

class otto : public QDialog
{
    Q_OBJECT

public:
    explicit otto(QWidget *parent = nullptr);
    ~otto();
    //int amount;

    void setIdAccount(const QString &newIdAccount);

    void setWebToken(const QByteArray &newWebToken);

private slots:
    void updateBalanceSlot (QNetworkReply *reply);
    void getBalanceSlot (QNetworkReply *reply);
    void on_pushButton20_clicked();
    void on_pushButton40_clicked();
    void on_pushButton60_clicked();
    void on_pushButton90_clicked();
    void on_pushButton140_clicked();
    void on_pushButton240_clicked();
    void on_pushButtonMuuSumma_clicked();
    void on_pushButtonAlkuun_clicked();
    void updateBalance(int amount);
    void sendUpdatedBalance(int newBalance);


private:
    Ui::otto *ui;
    QNetworkAccessManager *putBalance;
    QNetworkAccessManager *getBalanceManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray webToken;
    //QString idAccount;
    int amount;
};

#endif // OTTO_H
