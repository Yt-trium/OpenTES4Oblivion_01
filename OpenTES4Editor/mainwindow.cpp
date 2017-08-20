#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    qDebug() << "-> on_actionQuit_triggered()";
    QCoreApplication::quit();
    qDebug() << "<- on_actionQuit_triggered()";
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug() << "-> on_actionOpen_triggered()";

    QString filename =
            QFileDialog::getOpenFileName(this,
                                         "Open TES4 Oblivion File",
                                         NULL,
                                         "Oblivion File (*.bsa *.esm *.esp)");

    if(!filename.isEmpty())
    {
        QFileInfo fileInfo(filename);

        if(fileInfo.completeSuffix() == "bsa")
            bsa(filename);
        if(fileInfo.completeSuffix() == "esm")
            esm(filename);
        if(fileInfo.completeSuffix() == "esp")
            esp(filename);
    }

    qDebug() << "<- on_actionOpen_triggered()";
}

void MainWindow::bsa(QString filename)
{
    qDebug() << "-> bsa(" << filename << ")";

    TES4FileBSA *bsafile = new TES4FileBSA(filename.toStdString());

    TES4FileBSA_UI *bsaui = new TES4FileBSA_UI(this, ui->mdiArea, bsafile);

    QFileInfo fileInfo(filename);
    bsaui->setWindowTitle(QString("TES4FileBSA " + fileInfo.fileName()));

    ui->mdiArea->addSubWindow(bsaui);
    bsaui->show();

    qDebug() << "<- bsa(" << filename << ")";
}

void MainWindow::esm(QString filename)
{
    qDebug() << "-> esm(" << filename << ")";
    qDebug() << "<- esm(" << filename << ")";
}

void MainWindow::esp(QString filename)
{
    qDebug() << "-> esp(" << filename << ")";
    qDebug() << "<- esp(" << filename << ")";
}
