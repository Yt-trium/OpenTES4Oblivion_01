#ifndef TES4FILEBSA_H
#define TES4FILEBSA_H

#include <iostream>
#include <fstream>
#include <bitset>

#include <zlib.h>

#include "tes4files.h"
#include "tes4filebsastructs.h"

class TES4FileBSA
{
public:
    TES4FileBSA(std::string f);

    BSAHeader getHeader();
    std::vector<FolderRecord> getFolderRecords();
    std::vector<FileRecordBlock> getFileRecordBlocks();
    std::vector<std::string> getFileNameBlock();

    void read();

private:
    std::string filename;

    // header
    BSAHeader header;

    // folderRecords
    std::vector<FolderRecord> folderRecords;

    // fileRecordBlocks
    std::vector<FileRecordBlock> fileRecordBlocks;

    // fileNameBlock
    std::vector<std::string> fileNameBlock;
};

#endif // TES4FILEBSA_H
