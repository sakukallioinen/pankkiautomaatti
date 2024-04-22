#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSerialPort/QSerialPort>
#include <QMainWindow>
#include "pininterface.h"
#include "paasivu.h"
#include "otto.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

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
    void pinHandlerSlot(QString);
    void checkCardSlot(QNetworkReply *reply);
    void checkPinSlot(QNetworkReply *reply);
    void handleAccountIdResponse(QNetworkReply *reply);

signals:
    void pinSignal();

private:
    QNetworkAccessManager *checkCardManager;
    QNetworkAccessManager *checkPinManager;
    QNetworkAccessManager *accountIdManager;
    QNetworkReply *reply;
    QByteArray response_data;
    Ui::MainWindow *ui;
    PinInterface *pinInterface;

    void fetchAccountId(const QString &webToken);
};
#endif // MAINWINDOW_H
