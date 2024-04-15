#include "mainwindow.h"
#include "rfidreader.h" // Lisää tämä

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Luo MainWindow-olio ja näytä se
    MainWindow w;
    w.show();

    // Luo rfidreader-olio ja näytä se
    rfidreader reader;
    reader.show();

    return a.exec();
}
