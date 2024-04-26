#include "tapahtumat.h"
#include "ui_tapahtumat.h"

tapahtumat::tapahtumat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tapahtumat)
{
    ui->setupUi(this);
}

tapahtumat::~tapahtumat()
{
    delete ui;
}

void tapahtumat::on_backBtn_clicked()
{
    this->close();
}

void tapahtumat::setTapahtumatString(const QString &newTapahtumatString)
{
    tapahtumatString = newTapahtumatString;
    ui->textEdit->setText(tapahtumatString);
}
