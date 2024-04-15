#include "rfidreader.h"
#include <QDebug>

rfidreader::rfidreader(QWidget *parent) :
    QMainWindow(parent),
    serial(new QSerialPort(this))
{
    QString portName = "COM7";
    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::Baud9600);
    if (!serial->open(QIODevice::ReadOnly)) {
        qDebug() << "Sarjaportin avaaminen epäonnistui:" << serial->errorString();
        return;
    }
    qDebug() << "RFID-lukija kytketty porttiin" << portName;

    connect(serial, &QSerialPort::readyRead, this, &rfidreader::readData);
}

rfidreader::~rfidreader() {
    serial->close();
    delete serial;
}

void rfidreader::readData() {
    QByteArray data = serial->readAll();
    qDebug() << "Luettu RFID-tieto:" << data;
}
