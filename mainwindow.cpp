#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("X Calculator");

    ui->dispTxt->setReadOnly(true);
    ui->dispTxt->setWordWrapMode(QTextOption::NoWrap);

    connect(ui->enterBtn, SIGNAL(clicked()), this, SLOT(cmdProcess()));
    connect(ui->cmdLin, SIGNAL(returnPressed()), ui->enterBtn, SIGNAL(clicked()));

    ui->cmdLin->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cmdProcess()
{
    ui->dispTxt->append(ui->cmdLin->text().append("\n"));
    ui->dispTxt->append(process(ui->cmdLin->text().toStdString()).c_str());
    ui->cmdLin->clear();

    ui->cmdLin->setFocus();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_helpBtn_clicked()
{
    ui->dispTxt->append("\n--EXAMPLES--\n"
                        "x=1\n"
                        "y=sin(1)\n"
                        "x+y\n\n"
                        "x=[1,2;3,4]\n"
                        "y=pow(x,2)\n"
                        "z=pow([1,2;3,4],2)\n"
                        "y+z\n\n"
                        "x=[1,2,3,4,5,6,7,8,9,10]\n"
                        "y=[1,4,9,16,25,36,49,64,81,100]\n"
                        "plot(x@y@10)\n\n"
                        "one=[1,1,1,1,1;1;1;1;1,1]\n"
                        "cc=col(one,5)\n"
                        "rr=row(one,5)\n"
                        "m=one*one\n"
                        "foo=one+[1,1,1,1,1;1;1;1;1]\n\n"
                        "a=add(foo,2)\n"
                        "s=sub(foo,2)\n"
                        "m=mul(foo,2)\n"
                        "d=div(foo,2)\n\n"
                        "--You can try these commands on your own--\n\n");
}

void MainWindow::on_aboutBtn_clicked()
{
    QMessageBox::about ( this, tr("About"), tr("X Calculator is a small calculator\n that manipulates matrices and plots") ) ;
    ui->cmdLin->setFocus();
}

void MainWindow::on_dispTxt_textChanged()
{
    QTextCursor cursor = ui->dispTxt->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->dispTxt->setTextCursor(cursor);
}
