#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        // Create the main app window
        MainWindow window;

        window.show();
        window.setWindowTitle("Шевченків гай");

        return a.exec();
}
