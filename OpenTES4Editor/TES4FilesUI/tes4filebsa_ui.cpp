#include "tes4filebsa_ui.h"
#include "ui_tes4filebsa_ui.h"

TES4FileBSA_UI::TES4FileBSA_UI(QWidget *parent, QMdiArea *mdi, TES4FileBSA *bsa) :
    QWidget(parent),
    ui(new Ui::TES4FileBSA_UI)
{
    ui->setupUi(this);
    this->mdiArea = mdi;
    this->bsa = bsa;

    read();

    updateUI();
}

TES4FileBSA_UI::~TES4FileBSA_UI()
{
    delete ui;
}

void TES4FileBSA_UI::read()
{
    bsa->read();
}

void TES4FileBSA_UI::updateUI()
{
    unsigned int i=0,j=0,k=0;

    // header
    ui->label_fileId_->setText(QString(bsa->getHeader().fileId));
    ui->label_version_->setText(QString::number(bsa->getHeader().version));
    ui->label_offset_->setText(QString::number(bsa->getHeader().offset));
    ui->label_archiveFlags_->setText(QString::number(bsa->getHeader().archiveFlags,2));
    ui->label_folderCount_->setText(QString::number(bsa->getHeader().folderCount));
    ui->label_fileCount_->setText(QString::number(bsa->getHeader().fileCount));
    ui->label_totalFolderNameLength_->setText(QString::number(bsa->getHeader().totalFolderNameLength));
    ui->label_totalFileNameLength_->setText(QString::number(bsa->getHeader().totalFileNameLength));
    ui->label_fileFlags_->setText(QString::number(bsa->getHeader().fileFlags,2));

    // folderRecords
    std::vector<FolderRecord> folderRecords = bsa->getFolderRecords();
    for(i=0;i<folderRecords.size();i++)
    {
        ui->tableWidget_FolderRecords->insertRow(ui->tableWidget_FolderRecords->rowCount());

        FolderRecord folderRecord = folderRecords.at(i);

        ui->tableWidget_FolderRecords->setItem(i,0,new QTableWidgetItem(QString::number(folderRecord.nameHash,16).toUpper()));
        ui->tableWidget_FolderRecords->setItem(i,1,new QTableWidgetItem(QString::number(folderRecord.count)));
        ui->tableWidget_FolderRecords->setItem(i,2,new QTableWidgetItem(QString::number(folderRecord.offset)));
    }
    ui->tableWidget_FolderRecords->resizeColumnsToContents();
    ui->tableWidget_FolderRecords->resizeRowsToContents();

    // fileRecordBlocks & fileNameBlock
    this->fileRecordBlocks = bsa->getFileRecordBlocks();
    std::vector<std::string> fileNameBlock = bsa->getFileNameBlock();

    for(i=0;i<fileRecordBlocks.size();i++)
    {
        FileRecordBlock fileRecordBlock = fileRecordBlocks.at(i);

        QTreeWidgetItem *fileRecordBlockTreeItem = new QTreeWidgetItem(ui->treeWidget_FileRecordBlocksAndFileNameBlock);
        QTreeWidgetItem *fileRecordTreeItem;
        fileRecordBlockTreeItem->setText(0, QString(fileRecordBlock.name.string));

        for(j=0;j<fileRecordBlock.fileRecord.size();j++)
        {
            FileRecord fileRecord = fileRecordBlock.fileRecord.at(j);

            fileRecordTreeItem = new QTreeWidgetItem(fileRecordBlockTreeItem);

            fileRecordTreeItem->setText(1, QString::number(fileRecord.nameHash,16));
            fileRecordTreeItem->setText(2, QString::number(fileRecord.size));
            fileRecordTreeItem->setText(3, QString::number(fileRecord.offset));

            if(fileNameBlock.size() > k)
                fileRecordTreeItem->setText(4, QString(fileNameBlock.at(k).c_str()));

            k++;
        }
        // fileRecordBlockTreeItem->addChild(fileRecordTreeItem);
    }

    for(int i = 0; i < 5; i++)
        ui->treeWidget_FileRecordBlocksAndFileNameBlock->resizeColumnToContents(i);
}

void TES4FileBSA_UI::on_pushButton_Open_clicked()
{
    QModelIndex index = ui->treeWidget_FileRecordBlocksAndFileNameBlock->currentIndex();
    if(!(index.isValid() && index.parent().isValid()))
        return;

    FileRecord fr = fileRecordBlocks.at(index.parent().row()).fileRecord.at(index.row());
    File f = bsa->getFile(fr);

    QTextEdit *data = new QTextEdit();
    data->setText(QString::fromLatin1(f.data,fr.size));

    QMdiSubWindow *subWindowRead = new QMdiSubWindow;
    subWindowRead->setParent(mdiArea);
    subWindowRead->setWidget(data);
    subWindowRead->setAttribute(Qt::WA_DeleteOnClose);
    subWindowRead->setWindowTitle(QString::number(fr.nameHash,16).toUpper());
    subWindowRead->show();

    // mdiArea->addSubWindow(subWindowRead);
}

void TES4FileBSA_UI::on_pushButton_Save_clicked()
{
    QModelIndex index = ui->treeWidget_FileRecordBlocksAndFileNameBlock->currentIndex();
    if(!(index.isValid() && index.parent().isValid()))
        return;

    FileRecord fr = fileRecordBlocks.at(index.parent().row()).fileRecord.at(index.row());
    File f = bsa->getFile(fr);

    QString filename =
            QFileDialog::getSaveFileName(this,
                                         "Save file");

    if(!filename.isEmpty())
    {
        std::ofstream outfile (filename.toStdString().c_str(),std::ofstream::binary);
        outfile.write(f.data, fr.size);
    }
}
