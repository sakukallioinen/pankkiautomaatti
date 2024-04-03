#include "paasivu.h"
#include "ui_paasivu.h"

paasivu::paasivu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::paasivu)
{
    ui->setupUi(this);
    connect(ui->logOutPushButton, SIGNAL(clicked()), this, SLOT(on_logoutPushButton_clicked()));
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

}

void paasivu::on_logoutPushButton_clicked()
{
    this->close();
}

void paasivu::on_chooseAccountPushButton_clicked()
{

}

void paasivu::asetaTeksti()
{

    ui->label->setText("Tervetuloa");
}
