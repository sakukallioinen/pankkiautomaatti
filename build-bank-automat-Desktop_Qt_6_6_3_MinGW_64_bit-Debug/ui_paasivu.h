/********************************************************************************
** Form generated from reading UI file 'paasivu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAASIVU_H
#define UI_PAASIVU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_paasivu
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *paasivu)
    {
        if (paasivu->objectName().isEmpty())
            paasivu->setObjectName("paasivu");
        paasivu->resize(517, 435);
        label = new QLabel(paasivu);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 100, 341, 181));
        QFont font;
        font.setPointSize(27);
        label->setFont(font);
        label_2 = new QLabel(paasivu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 230, 161, 41));

        retranslateUi(paasivu);

        QMetaObject::connectSlotsByName(paasivu);
    } // setupUi

    void retranslateUi(QDialog *paasivu)
    {
        paasivu->setWindowTitle(QCoreApplication::translate("paasivu", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("paasivu", "Tervetuloa pankkiin!", nullptr));
        label_2->setText(QCoreApplication::translate("paasivu", "Jatkamme my\303\266hemmin...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paasivu: public Ui_paasivu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAASIVU_H
