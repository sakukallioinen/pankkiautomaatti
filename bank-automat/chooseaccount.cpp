#include "chooseaccount.h"
#include "ui_chooseaccount.h"

chooseaccount::chooseaccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chooseaccount)
{
    ui->setupUi(this);
}

chooseaccount::~chooseaccount()
{
    delete ui;
}
