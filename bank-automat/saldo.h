#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Saldo;
}

class Saldo : public QDialog
{
    Q_OBJECT

public:
    explicit Saldo(QWidget *parent = nullptr);
    ~Saldo();


    void setCredit(const QString &newCredit);

    void setBalance(const QString &newBalance);

private slots:
    void on_btnLopeta_clicked();

private:
    Ui::Saldo *ui;
    QString balance;
    QString credit;
};

#endif // SALDO_H
