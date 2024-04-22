#include "rfidreader.h"
#include <QDebug>
#include <QString>
#include "pininterface.h"
#include "mainwindow.h"

rfidreader::rfidreader(PinInterface *pinInterface, QWidget *parent) :
    QMainWindow(parent),
    serial(new QSerialPort(this)),
    pinInterface(pinInterface)
{
    QString portName = "COM5";
    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::Baud9600);
    if (!serial->open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open serial port:" << serial->errorString();
        return;
    }
    qDebug() << "RFID reader connected to port:" << portName;

    connect(serial, &QSerialPort::readyRead, this, &rfidreader::readData);
}

rfidreader::~rfidreader() {
    serial->close();
    delete serial;
}

void rfidreader::readData() {
    QByteArray data = serial->readAll();
    QString cardID = QString(data).trimmed();
    QRegularExpression re("[^0-9]");
    cardID.remove(re);
    qDebug() << "Read RFID data:" << data;
    emit cardRead(cardID);
}
