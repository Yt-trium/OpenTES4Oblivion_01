#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>

#include "TES4Files/tes4files.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;

    void bsa(QString filename);
    void esm(QString filename);
    void esp(QString filename);
};

#endif // MAINWINDOW_H
