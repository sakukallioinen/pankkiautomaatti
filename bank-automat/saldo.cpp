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

void Saldo::updateBalance(QString balance)
{
    ui->label_3->setText(balance);
}
