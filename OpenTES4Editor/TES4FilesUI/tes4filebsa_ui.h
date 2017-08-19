#ifndef TES4FILEBSA_UI_H
#define TES4FILEBSA_UI_H

#include <QWidget>

namespace Ui {
class TES4FileBSA_UI;
}

class TES4FileBSA_UI : public QWidget
{
    Q_OBJECT

public:
    explicit TES4FileBSA_UI(QWidget *parent = 0);
    ~TES4FileBSA_UI();

private:
    Ui::TES4FileBSA_UI *ui;
};

#endif // TES4FILEBSA_UI_H
