#include "saldo.h"
#include "ui_saldo.h"

Saldo::Saldo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Saldo)
{
    ui->setupUi(this);
}

Saldo::~Saldo()
{
    delete ui;
}

void Saldo::on_btnLopeta_clicked()
{

    this->close();
}

void Saldo::setBalance(const QString &newBalance)
{
    balance = newBalance;
    ui->labelBalance->setText(balance);
}

void Saldo::setCredit(const QString &newCredit)
{
    credit = newCredit;
    ui->labelCredit->setText(credit);
}


