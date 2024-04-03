#ifndef OTTO_H
#define OTTO_H

#include <QDialog>

namespace Ui {
class otto;
}

class otto : public QDialog
{
    Q_OBJECT

public:
    explicit otto(QWidget *parent = nullptr);
    ~otto();

private slots:
    void on_pushButton20_clicked();
    void on_pushButton40_clicked();
    void on_pushButton60_clicked();
    void on_pushButton90_clicked();
    void on_pushButton140_clicked();
    void on_pushButton240_clicked();
    void on_pushButtonMuuSumma_clicked();
    void on_pushButtonAlkuun_clicked();


private:
    Ui::otto *ui;
};

#endif // OTTO_H
