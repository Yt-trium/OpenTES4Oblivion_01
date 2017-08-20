#ifndef TES4FILEBSASTRUCTS_H
#define TES4FILEBSASTRUCTS_H

#include <vector>

#include "tes4filestypes.h"

typedef struct
{
    char fileId[4];
    ulong_ version;
    ulong_ offset;
    ulong_ archiveFlags;
    ulong_ folderCount;
    ulong_ fileCount;
    ulong_ totalFolderNameLength;
    ulong_ totalFileNameLength;
    ulong_ fileFlags;
}BSAHeader;

typedef struct
{
    uint64_t nameHash;
    ulong_ count;
    ulong_ offset;
}FolderRecord;

typedef struct
{
    uint64_t nameHash;
    ulong_ size;
    ulong_ offset;
}FileRecord;

typedef struct
{
    BZstring name;
    std::vector<FileRecord> fileRecord;
}FileRecordBlock;

typedef struct
{
    char *data;
}File;

typedef struct
{
    ulong_ originalSize;
    char *data;
}CompressedFile;

#endif // TES4FILEBSASTRUCTS_H
