#ifndef CHOOSEACCOUNT_H
#define CHOOSEACCOUNT_H

#include <QDialog>

namespace Ui {
class chooseaccount;
}

class chooseaccount : public QDialog
{
    Q_OBJECT

public:
    explicit chooseaccount(QWidget *parent = nullptr);
    ~chooseaccount();

private:
    Ui::chooseaccount *ui;
};

#endif // CHOOSEACCOUNT_H
