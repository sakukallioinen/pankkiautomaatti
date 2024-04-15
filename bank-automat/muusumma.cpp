#include "muusumma.h"
#include "Qpushbutton.h"
#include "ui_muusumma.h"

MuuSumma::MuuSumma(QWidget *parent)
    :QDialog(parent),
    ui(new Ui::MuuSumma)
{
    ui->setupUi(this);
    ui->PinLineEdit->setFocusPolicy(Qt::NoFocus);
    connect(ui->enterButton, SIGNAL(clicked(bool)), this, SLOT(enterClicked()));
}

MuuSumma::~MuuSumma()
{
    delete ui;
}

void MuuSumma::on_N1_clicked()
{
    numberClicked();
}


void MuuSumma::on_N2_clicked()
{
    numberClicked();
}


void MuuSumma::on_N3_clicked()
{
    numberClicked();
}


void MuuSumma::on_N4_clicked()
{
    numberClicked();
}


void MuuSumma::on_N5_clicked()
{
    numberClicked();
}


void MuuSumma::on_N6_clicked()
{
    numberClicked();
}


void MuuSumma::on_N7_clicked()
{
    numberClicked();
}


void MuuSumma::on_N8_clicked()
{
    numberClicked();
}


void MuuSumma::on_N9_clicked()
{
    numberClicked();
}


void MuuSumma::on_N0_clicked()
{
    numberClicked();
}

void MuuSumma::numberClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString name = button->objectName();

    // Remove the first character from the object name
    pin = pin + name.last(1);
}

void MuuSumma::enterClicked()
{
    //qDebug()<<"klikki";
    //QString s = ui->PinLineEdit->text();
    emit pinEntered(pin);
    pin.clear();
    ui->PinLineEdit->clear();
    this->close();
}
