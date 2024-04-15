#ifndef RFIDREADER_H
#define RFIDREADER_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class rfidreader;
}
QT_END_NAMESPACE

class rfidreader : public QMainWindow
{
    Q_OBJECT

public:
    explicit rfidreader(QWidget *parent = nullptr);
    ~rfidreader();

private slots:
    void readData();

private:
    QSerialPort *serial;
};

#endif // RFIDREADER_H
