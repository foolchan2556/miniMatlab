#include <QPrinter>

#include <QSvgGenerator>
#include <QFileDialog>
#include <QPrintDialog>
#include <QInputDialog>

#include <qwt_math.h>
#include <qwt_scale_engine.h>
#include <qwt_symbol.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <qwt_text.h>

#include "plotter.h"
#include "ui_plotter.h"

Plotter::Plotter(double *x, double *y, int size,
                 const string & title,
                 const string & xtitle,
                 const string & ytitle,
                 const string & c1title,
                 QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Plotter)
{
    ui->setupUi(this);

    connect(ui->exportBtn, SIGNAL(clicked()), this, SLOT(exportSVG()));
    connect(ui->printBtn, SIGNAL(clicked()), this, SLOT(print()));

    ui->plotDisp->setAutoReplot(false);

    bool ok;
    QString text = QInputDialog::getText(this, tr("Set Plot Title"),
                                         tr("Plot Title"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty())
        ui->plotDisp->setTitle(text);
    else
        ui->plotDisp->setTitle(title.c_str());

    ui->plotDisp->setCanvasBackground(QColor(Qt::white));

    // legend
    QwtLegend *legend = new QwtLegend(ui->plotDisp);
    legend->setFrameStyle(QFrame::Box|QFrame::Sunken);
    ui->plotDisp->insertLegend(legend, QwtPlot::BottomLegend);

    // axes
    text = QInputDialog::getText(this, tr("Set X Axis Title"),
                                             tr("X Title:"), QLineEdit::Normal,
                                             "", &ok);
        if (ok && !text.isEmpty())
            ui->plotDisp->setAxisTitle(QwtPlot::xBottom, text);
        else
            ui->plotDisp->setAxisTitle(QwtPlot::xBottom, xtitle.c_str());
    text = QInputDialog::getText(this, tr("Set Y Axis Title"),
                                                 tr("Y Title:"), QLineEdit::Normal,
                                                 "", &ok);
        if (ok && !text.isEmpty())
            ui->plotDisp->setAxisTitle(QwtPlot::yLeft, text);
        else
            ui->plotDisp->setAxisTitle(QwtPlot::yLeft, ytitle.c_str());

    text = QInputDialog::getText(this, tr("Set Curve Name"),
                                                     tr("Curve Name:"), QLineEdit::Normal,
                                                     "", &ok);
        if (ok && !text.isEmpty())
            d_crv1 = new QwtPlotCurve(text);
        else
            d_crv1 = new QwtPlotCurve(c1title.c_str());

    d_crv1->setRenderHint(QwtPlotItem::RenderAntialiased);
    d_crv1->setPen(QPen(Qt::darkBlue));
    d_crv1->setYAxis(QwtPlot::yLeft);
    d_crv1->attach(ui->plotDisp);

    ui->plotDisp->setAutoReplot(true);

    setData(x, y, size);
}

Plotter::~Plotter()
{
    delete ui;
}

void Plotter::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Plotter::setData(double *x, double *y, int size)
{
    d_crv1->setData(x, y, size);
}

void Plotter::exportSVG()
{
    QString fileName = "plot.svg";

    fileName = QFileDialog::getSaveFileName(
        this, "Export File Name", QString(),
        "SVG Documents (*.svg)");

    if ( !fileName.isEmpty() )
    {
        QSvgGenerator generator;
        generator.setFileName(fileName);
        generator.setSize(this->size());

        ui->plotDisp->print(generator);
    }
}

void Plotter::print()
{
    QPrinter printer;

    QString docName = ui->plotDisp->title().text();
    if ( !docName.isEmpty() )
    {
        docName.replace (QRegExp (QString::fromLatin1 ("\n")), tr (" -- "));
        printer.setDocName (docName);
    }

    printer.setCreator("Data Plot");
    printer.setOrientation(QPrinter::Landscape);

    QPrintDialog dialog(&printer);
    if ( dialog.exec() )
    {
        QwtPlotPrintFilter filter;
        if ( printer.colorMode() == QPrinter::GrayScale )
        {
            int options = QwtPlotPrintFilter::PrintAll;
            options &= ~QwtPlotPrintFilter::PrintBackground;
            options |= QwtPlotPrintFilter::PrintFrameWithScales;
            filter.setOptions(options);
        }
        ui->plotDisp->print(printer, filter);
    }
}
