#ifndef TAPAHTUMAT_H
#define TAPAHTUMAT_H

#include <QDialog>

namespace Ui {
class tapahtumat;
}

class tapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit tapahtumat(QWidget *parent = nullptr);
    ~tapahtumat();

    void setTapahtumatString(const QString &newTapahtumatString);

private slots:
    void on_backBtn_clicked();

private:
    Ui::tapahtumat *ui;
    QString tapahtumatString;
};

#endif // TAPAHTUMAT_H
