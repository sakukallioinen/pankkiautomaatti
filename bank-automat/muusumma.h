#ifndef MUUSUMMA_H
#define MUUSUMMA_H
#include <QDialog>

namespace Ui {
class MuuSumma;
}

class MuuSumma : public QDialog
{
    Q_OBJECT

public:
    explicit MuuSumma(QWidget *parent = nullptr);
    ~MuuSumma();

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
    void pinEntered(int);

private:
    Ui::MuuSumma *ui;
    void numberClicked();
    QString pin;
};

#endif // MUUSUMMA_H
