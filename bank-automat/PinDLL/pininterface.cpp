#include "pininterface.h"
#include "ui_pininterface.h"

PinInterface::PinInterface(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PinInterface)
{
    ui->setupUi(this);
    ui->PinLineEdit->setFocusPolicy(Qt::NoFocus);
    connect(ui->enterButton, SIGNAL(clicked(bool)), this, SLOT(enterClicked()));
}

PinInterface::~PinInterface()
{
    delete ui;
}

void PinInterface::on_N1_clicked()
{
    numberClicked();
}


void PinInterface::on_N2_clicked()
{
    numberClicked();
}


void PinInterface::on_N3_clicked()
{
    numberClicked();
}


void PinInterface::on_N4_clicked()
{
    numberClicked();
}


void PinInterface::on_N5_clicked()
{
    numberClicked();
}


void PinInterface::on_N6_clicked()
{
    numberClicked();
}


void PinInterface::on_N7_clicked()
{
    numberClicked();
}


void PinInterface::on_N8_clicked()
{
    numberClicked();
}


void PinInterface::on_N9_clicked()
{
    numberClicked();
}


void PinInterface::on_N0_clicked()
{
    numberClicked();
}

void PinInterface::numberClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString name = button->objectName();

    // Remove the first character from the object name
    pin = pin + name.last(1);

    QString hiddenPin;
    for (int i = 0; i < pin.length(); i++) {
        hiddenPin.append('*');
    }
    ui->PinLineEdit->setText(hiddenPin);
}

void PinInterface::enterClicked()
{
    //qDebug()<<"klikki";
    //QString s = ui->PinLineEdit->text();
    emit pinEntered(pin);
    pin.clear();
    ui->PinLineEdit->clear();
    this->close();
}

