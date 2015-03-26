#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "cmdengine.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_dispTxt_textChanged();
    void on_aboutBtn_clicked();
    void on_helpBtn_clicked();
    void cmdProcess();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
