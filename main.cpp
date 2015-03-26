#include <QtGui/QApplication>
#include "mainwindow.h"
#include "plotter.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*int size = 5;
    double x[] = {1, 2, 2, 1};
    double y[] = {2, 2, 3, 3};
    Plotter plotter(x, y, size, "New TITLE", "X AXIS", "Y AXIS",
                    "CURVE!!");
    plotter.show();*/
    return a.exec();
}
