#include "paasivu.h"
#include "saldo.h"
#include "tilinvalinta.h"
#include "ui_paasivu.h"

paasivu::paasivu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::paasivu)
{
    ui->setupUi(this);
    connect(ui->logOutPushButton, SIGNAL(clicked()), this, SLOT(close()));
}

paasivu::~paasivu()
{
    delete ui;
}

void paasivu::on_actionsPushButton_clicked()
{

}

void paasivu::on_getMoneyPushButton_clicked()
{

}

void paasivu::on_balancePushButton_clicked()
{
    Saldo *objectSaldo=new Saldo(this);
    objectSaldo->show();

}


void paasivu::on_logoutPushButton_clicked()
{

}

void paasivu::on_chooseAccountPushButton_clicked()
{
    Tilinvalinta *objectTilinValinta=new Tilinvalinta(this);
    objectTilinValinta->show();
}

void paasivu::asetaTeksti()
{

    ui->label->setText("Tervetuloa");
}
