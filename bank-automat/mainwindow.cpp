#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pinInterface = new PinInterface(this);
    connect(ui->pushButtonCardReader, SIGNAL(clicked()), this, SLOT(on_pushButtonCardReader_clicked()));
    connect(pinInterface, SIGNAL(pinEntered(QString)), this, SLOT(pinHandler(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCardReader_clicked()
{
    clickHandler();
}

void MainWindow::clickHandler()
{
    if(ui->lineEditCardNum->text().toInt() == cardNumber)
    {
        pinInterface->open();
    }
    else
    {
        ui->label->setText("Invalid card number");
    }
}

void MainWindow::pinHandler(QString s)
{
    if(s.toInt() == cardPin)
    {
        //ui->label->setText("Pin correct");
        paasivu p;
        p.setModal(true);
        p.exec();
        delete ui;

    }
    else
    {
        ui->label->setText("Pin incorrect");
    }
}

