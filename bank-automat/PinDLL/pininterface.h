#ifndef PININTERFACE_H
#define PININTERFACE_H
#include "PinDLL_global.h"
#include <QDialog>
#include <QDebug>

namespace Ui {
class PinInterface;
}

class PINDLL_EXPORT PinInterface : public QDialog
{
    Q_OBJECT

public:
    explicit PinInterface(QWidget *parent = nullptr);
    ~PinInterface();

private slots:
    void on_N1_clicked();

    void on_N2_clicked();

    void on_N3_clicked();

    void on_N4_clicked();

    void on_N5_clicked();

    void on_N6_clicked();

    void on_N7_clicked();

    void on_N8_clicked();

    void on_N9_clicked();

    void on_N0_clicked();

    void enterClicked();

signals:
    void pinEntered(QString);

private:
    Ui::PinInterface *ui;
    void numberClicked();
    QString pin;
};

#endif // PININTERFACE_H
