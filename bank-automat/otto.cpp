#include "otto.h"
#include "ui_otto.h"

otto::otto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otto)
{
    ui->setupUi(this);
    connect(ui->pushButtonAlkuun, SIGNAL(Clicked()), this, SLOT(close()));
}

otto::~otto()
{
    delete ui;
}

void otto::on_pushButton20_clicked()
{

}
void otto::on_pushButton40_clicked()
{

}
void otto::on_pushButton60_clicked()
{

}
void otto::on_pushButton90_clicked()
{

}
void otto::on_pushButton140_clicked()
{

}
void otto::on_pushButton240_clicked()
{

}
void otto::on_pushButtonMuuSumma_clicked()
{

}
void otto::on_pushButtonAlkuun_clicked()
{
    this->close();

}
