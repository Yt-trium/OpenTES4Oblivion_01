#include "tes4filebsa_ui.h"
#include "ui_tes4filebsa_ui.h"

TES4FileBSA_UI::TES4FileBSA_UI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TES4FileBSA_UI)
{
    ui->setupUi(this);
}

TES4FileBSA_UI::~TES4FileBSA_UI()
{
    delete ui;
}
