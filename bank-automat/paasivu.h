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

private:
    Ui::paasivu *ui;
};

#endif // PAASIVU_H
