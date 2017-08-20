#include "tes4filebsa.h"

TES4FileBSA::TES4FileBSA(std::string f)
{
    this->filename = f;
}

BSAHeader TES4FileBSA::getHeader()
{
    return header;
}

std::vector<FolderRecord> TES4FileBSA::getFolderRecords()
{
    return folderRecords;
}

std::vector<FileRecordBlock> TES4FileBSA::getFileRecordBlocks()
{
    return fileRecordBlocks;
}

std::vector<std::string> TES4FileBSA::getFileNameBlock()
{
    return fileNameBlock;
}

void TES4FileBSA::read()
{
    unsigned int i,j;

    std::ifstream file;
    file.open(filename, std::ifstream::binary);

    // header
    file.read(header.fileId,4);
    file.read((char*) (&header.version), sizeof(header.version));
    file.read((char*) (&header.offset), sizeof(header.offset));
    file.read((char*) (&header.archiveFlags), sizeof(header.archiveFlags));
    file.read((char*) (&header.folderCount), sizeof(header.folderCount));
    file.read((char*) (&header.fileCount), sizeof(header.fileCount));
    file.read((char*) (&header.totalFolderNameLength), sizeof(header.totalFolderNameLength));
    file.read((char*) (&header.totalFileNameLength), sizeof(header.totalFileNameLength));
    file.read((char*) (&header.fileFlags), sizeof(header.fileFlags));

    std::bitset<32> archiveFlags(header.archiveFlags);

    // folderRecords
    FolderRecord folderRecord;

    for(i=0;i<header.folderCount;i++)
    {
        file.read((char*) (&folderRecord.nameHash), sizeof(folderRecord.nameHash));
        file.read((char*) (&folderRecord.count), sizeof(folderRecord.count));
        file.read((char*) (&folderRecord.offset), sizeof(folderRecord.offset));
        folderRecords.push_back(folderRecord);
    }

    // fileRecordBlocks
    FileRecordBlock fileRecordBlock;

    for(i=0;i<header.folderCount;i++)
    {
        if(archiveFlags.test(0))
        {
            // bit 1 of archiveFlags is set
            file.read((char*) (&fileRecordBlock.name.length), sizeof(fileRecordBlock.name.length));
            fileRecordBlock.name.string = (char*) malloc(fileRecordBlock.name.length);
            file.read(fileRecordBlock.name.string, fileRecordBlock.name.length);
        }
        else
        {
            // bit 1 of archiveFlags is not set
            fileRecordBlock.name.length = 0;
            fileRecordBlock.name.string = NULL;
        }

        FileRecord fileRecord;

        for(j=0;j<folderRecords.at(i).count;j++)
        {
            file.read((char*) (&fileRecord.nameHash), sizeof(fileRecord.nameHash));
            file.read((char*) (&fileRecord.size), sizeof(fileRecord.size));
            file.read((char*) (&fileRecord.offset), sizeof(fileRecord.offset));

            fileRecordBlock.fileRecord.push_back(fileRecord);
        }

        fileRecordBlocks.push_back(fileRecordBlock);
        fileRecordBlock.fileRecord.clear();
    }

    // fileNameBlock
    if(archiveFlags.test(1))
    {
        // bit 2 of archiveFlags is set
        // list of lower case file names
        for(i=0;i<header.fileCount;i++)
        {
            std::string fnb;
            getline(file, fnb, '\0');
            fileNameBlock.push_back(fnb);
        }
    }

    file.close();
}
