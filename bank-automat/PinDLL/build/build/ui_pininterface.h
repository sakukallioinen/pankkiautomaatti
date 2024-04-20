/********************************************************************************
** Form generated from reading UI file 'pininterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PININTERFACE_H
#define UI_PININTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PinInterface
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *N1;
    QPushButton *N6;
    QPushButton *N7;
    QPushButton *N4;
    QPushButton *N9;
    QPushButton *N3;
    QPushButton *N5;
    QPushButton *N8;
    QPushButton *N2;
    QPushButton *N0;
    QPushButton *enterButton;
    QLineEdit *PinLineEdit;
    QLabel *label;

    void setupUi(QDialog *PinInterface)
    {
        if (PinInterface->objectName().isEmpty())
            PinInterface->setObjectName("PinInterface");
        PinInterface->resize(360, 410);
        horizontalLayout = new QHBoxLayout(PinInterface);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        N1 = new QPushButton(PinInterface);
        N1->setObjectName("N1");

        gridLayout->addWidget(N1, 0, 0, 1, 1);

        N6 = new QPushButton(PinInterface);
        N6->setObjectName("N6");

        gridLayout->addWidget(N6, 1, 2, 1, 1);

        N7 = new QPushButton(PinInterface);
        N7->setObjectName("N7");

        gridLayout->addWidget(N7, 2, 0, 1, 1);

        N4 = new QPushButton(PinInterface);
        N4->setObjectName("N4");

        gridLayout->addWidget(N4, 1, 0, 1, 1);

        N9 = new QPushButton(PinInterface);
        N9->setObjectName("N9");

        gridLayout->addWidget(N9, 2, 2, 1, 1);

        N3 = new QPushButton(PinInterface);
        N3->setObjectName("N3");

        gridLayout->addWidget(N3, 0, 2, 1, 1);

        N5 = new QPushButton(PinInterface);
        N5->setObjectName("N5");

        gridLayout->addWidget(N5, 1, 1, 1, 1);

        N8 = new QPushButton(PinInterface);
        N8->setObjectName("N8");

        gridLayout->addWidget(N8, 2, 1, 1, 1);

        N2 = new QPushButton(PinInterface);
        N2->setObjectName("N2");

        gridLayout->addWidget(N2, 0, 1, 1, 1);

        N0 = new QPushButton(PinInterface);
        N0->setObjectName("N0");

        gridLayout->addWidget(N0, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);

        enterButton = new QPushButton(PinInterface);
        enterButton->setObjectName("enterButton");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        enterButton->setFont(font);

        gridLayout_2->addWidget(enterButton, 1, 1, 1, 1);

        PinLineEdit = new QLineEdit(PinInterface);
        PinLineEdit->setObjectName("PinLineEdit");

        gridLayout_2->addWidget(PinLineEdit, 1, 0, 1, 1);

        label = new QLabel(PinInterface);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        label->setFont(font1);
        label->setLineWidth(1);
        label->setMidLineWidth(1);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        retranslateUi(PinInterface);

        QMetaObject::connectSlotsByName(PinInterface);
    } // setupUi

    void retranslateUi(QDialog *PinInterface)
    {
        PinInterface->setWindowTitle(QCoreApplication::translate("PinInterface", "Dialog", nullptr));
        N1->setText(QCoreApplication::translate("PinInterface", "1", nullptr));
        N6->setText(QCoreApplication::translate("PinInterface", "6", nullptr));
        N7->setText(QCoreApplication::translate("PinInterface", "7", nullptr));
        N4->setText(QCoreApplication::translate("PinInterface", "4", nullptr));
        N9->setText(QCoreApplication::translate("PinInterface", "9", nullptr));
        N3->setText(QCoreApplication::translate("PinInterface", "3", nullptr));
        N5->setText(QCoreApplication::translate("PinInterface", "5", nullptr));
        N8->setText(QCoreApplication::translate("PinInterface", "8", nullptr));
        N2->setText(QCoreApplication::translate("PinInterface", "2", nullptr));
        N0->setText(QCoreApplication::translate("PinInterface", "0", nullptr));
        enterButton->setText(QCoreApplication::translate("PinInterface", "Enter", nullptr));
        PinLineEdit->setText(QString());
        label->setText(QCoreApplication::translate("PinInterface", "Anna PIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PinInterface: public Ui_PinInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PININTERFACE_H
