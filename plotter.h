#ifndef PLOTTER_H
#define PLOTTER_H

#include <string>

#include <QDialog>

#include <qwt_plot.h>

class QwtPlotCurve;

using namespace std;

namespace Ui {
    class Plotter;
}

class Plotter : public QDialog {
    Q_OBJECT
public:
    Plotter(double *x, double *y, int size,
            const string & title = "Plot",
            const string & xtitle = "X Axis",
            const string & ytitle = "Y Axis",
            const string & c1title = "Curve",
            QWidget *parent = 0);
    ~Plotter();

protected:
    void changeEvent(QEvent *e);

private slots:
    void exportSVG();
    void print();

private:
    Ui::Plotter *ui;

    void setData(double *x, double *y, int size);

    QwtPlotCurve *d_crv1;
};

#endif // PLOTTER_H
