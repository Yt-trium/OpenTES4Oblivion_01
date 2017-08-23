#include "tes4fileesmp_ui.h"
#include "ui_tes4fileesmp_ui.h"

TES4FileESMP_UI::TES4FileESMP_UI(QWidget *parent, QMdiArea *mdi, TES4FileESMP *esmp) :
    QWidget(parent),
    ui(new Ui::TES4FileESMP_UI)
{
    ui->setupUi(this);
    this->mdiArea = mdi;
    this->esmp = esmp;

    read();

    updateUI();
}

TES4FileESMP_UI::~TES4FileESMP_UI()
{
    delete ui;
}

void TES4FileESMP_UI::read()
{
    esmp->read();
}

void TES4FileESMP_UI::updateUI()
{

}
