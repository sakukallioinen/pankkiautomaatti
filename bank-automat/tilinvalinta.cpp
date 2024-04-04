#include "tilinvalinta.h"
#include "ui_tilinvalinta.h"

Tilinvalinta::Tilinvalinta(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Tilinvalinta)
{
    ui->setupUi(this);
}

Tilinvalinta::~Tilinvalinta()
{
    delete ui;
}

void Tilinvalinta::on_BoxTilit_activated(int index)
{

}


void Tilinvalinta::on_btnTakaisin_clicked()
{
    this->close();
}

