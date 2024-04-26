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
    if (credit == "")
    {
        ui->labelCredit->hide();
        ui->labelLuotto->hide();
        ui->labelTilinSaldo->setText("Tilin saldo:");
        ui->labelBalance->setText(balance);
    }
    else {
        ui->labelCredit->setText(credit);
    }
}


void Saldo::setCredit(const QString &newCredit)
{
    credit = newCredit;
    if (balance == "")
    {
        ui->labelCredit->hide();
        ui->labelLuotto->hide();
        ui->labelBalance->setText(credit);
        ui->labelTilinSaldo->setText("Luottoa nostettavissa:");
    }
    else {
        ui->labelBalance->setText(balance);
    }
}


