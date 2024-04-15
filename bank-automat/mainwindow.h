#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSerialPort/QSerialPort>
#include <QMainWindow>
#include "pininterface.h"
#include "paasivu.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonCardReader_clicked();
    void clickHandler();
    void pinHandler(QString);

signals:
    void pinSignal();

private:
    Ui::MainWindow *ui;
    PinInterface *pinInterface;
    int cardNumber = 1234;
    short cardPin = 1234;
};
#endif // MAINWINDOW_H
