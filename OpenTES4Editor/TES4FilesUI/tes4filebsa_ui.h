#ifndef TES4FILEBSA_UI_H
#define TES4FILEBSA_UI_H

#include <QWidget>
#include <QDebug>
#include <QElapsedTimer>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QFileDialog>
#include <QTextEdit>
#include <QBuffer>
#include <QMediaPlayer>

#include "TES4Files/tes4files.h"

namespace Ui {
class TES4FileBSA_UI;
}

class TES4FileBSA_UI : public QWidget
{
    Q_OBJECT

public:
    explicit TES4FileBSA_UI(QWidget *parent = 0, QMdiArea *mdi = NULL, TES4FileBSA *bsa = NULL);
    ~TES4FileBSA_UI();

private slots:
    void on_pushButton_Open_clicked();
    void on_pushButton_Save_clicked();

    void on_treeWidget_FileRecordBlocksAndFileNameBlock_doubleClicked(const QModelIndex &index);

private:
    Ui::TES4FileBSA_UI *ui;
    QMdiArea *mdiArea;
    TES4FileBSA *bsa;
    std::vector<FileRecordBlock> fileRecordBlocks;

    void read();
    void updateUI();
};

#endif // TES4FILEBSA_UI_H
