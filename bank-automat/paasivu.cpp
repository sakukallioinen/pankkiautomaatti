#include "paasivu.h"
#include "saldo.h"
#include "tilinvalinta.h"
#include "ui_paasivu.h"
#include "otto.h"
#include "tapahtumat.h"

paasivu::paasivu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::paasivu)
{
    ui->setupUi(this);

    connect(ui->getMoneyPushButton, SIGNAL(Clicked()), this, SLOT(close()));

    connect(ui->logOutPushButton, SIGNAL(clicked()), this, SLOT(on_logoutPushButton_clicked()));

}

paasivu::~paasivu()
{
    delete ui;
}

void paasivu::on_ActionsPushButton_clicked()
{
    tapahtumat *objectTapahtumat=new tapahtumat(this);
    objectTapahtumat->show();
}

void paasivu::on_getMoneyPushButton_clicked()
{
    otto *ObjectOtto= new otto(this);
    ObjectOtto -> show();

}

void paasivu::on_balancePushButton_clicked()
{
    Saldo *objectSaldo=new Saldo(this);
    objectSaldo->show();

}


void paasivu::on_logoutPushButton_clicked()
{
    this->close();
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
