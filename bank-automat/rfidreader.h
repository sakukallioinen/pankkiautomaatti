#ifndef RFIDREADER_H
#define RFIDREADER_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include "pininterface.h"

class rfidreader : public QMainWindow
{
    Q_OBJECT

public:
    explicit rfidreader(PinInterface *pinInterface, QWidget *parent = nullptr);
    ~rfidreader();

signals:
    void cardRead(QString cardID);

private slots:
    void readData();

private:
    QSerialPort *serial;
    PinInterface *pinInterface;

};

#endif // RFIDREADER_H
