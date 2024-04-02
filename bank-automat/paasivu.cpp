#include "paasivu.h"
#include "ui_paasivu.h"

paasivu::paasivu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::paasivu)
{
    ui->setupUi(this);
}

paasivu::~paasivu()
{
    delete ui;
}
