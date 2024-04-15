#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>

namespace Ui {
class paasivu;
}

class paasivu : public QDialog
{
    Q_OBJECT

public:
    explicit paasivu(QWidget *parent = nullptr);
    ~paasivu();

private slots:
    void on_ActionsPushButton_clicked();
    void on_getMoneyPushButton_clicked();
    void on_balancePushButton_clicked();
    void on_logoutPushButton_clicked();
    void on_chooseAccountPushButton_clicked();

private:
    Ui::paasivu *ui;
    void asetaTeksti();
};

#endif // PAASIVU_H
