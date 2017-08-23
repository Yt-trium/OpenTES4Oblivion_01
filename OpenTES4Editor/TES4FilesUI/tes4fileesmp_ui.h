#ifndef TES4FILEESMP_UI_H
#define TES4FILEESMP_UI_H

#include <QWidget>
#include <QDebug>
#include <QElapsedTimer>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QFileDialog>

#include "TES4Files/tes4files.h"

namespace Ui {
class TES4FileESMP_UI;
}

class TES4FileESMP_UI : public QWidget
{
    Q_OBJECT

public:
    explicit TES4FileESMP_UI(QWidget *parent = 0, QMdiArea *mdi = NULL, TES4FileESMP *esmp = NULL);
    ~TES4FileESMP_UI();

private:
    Ui::TES4FileESMP_UI *ui;
    QMdiArea *mdiArea;
    TES4FileESMP *esmp;

    void read();
    void updateUI();
};

#endif // TES4FILEESMP_UI_H
