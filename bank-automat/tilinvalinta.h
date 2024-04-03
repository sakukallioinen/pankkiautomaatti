#ifndef TILINVALINTA_H
#define TILINVALINTA_H

#include <QDialog>

namespace Ui {
class Tilinvalinta;
}

class Tilinvalinta : public QDialog
{
    Q_OBJECT

public:
    explicit Tilinvalinta(QWidget *parent = nullptr);
    ~Tilinvalinta();

private slots:
    void on_BoxTilit_activated(int index);

    void on_btnTakaisin_clicked();

private:
    Ui::Tilinvalinta *ui;
};

#endif // TILINVALINTA_H
