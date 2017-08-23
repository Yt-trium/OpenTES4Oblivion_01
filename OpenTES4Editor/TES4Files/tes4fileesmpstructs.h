#ifndef TES4FILEESMPSTRUCTS_H
#define TES4FILEESMPSTRUCTS_H

#include <vector>

#include "tes4filestypes.h"

typedef struct
{
    char type[4];
    ulong_ dataSize;
    ulong_ flags;
    ulong_ formid;
    ulong_ versionControlInfo ;
    ubyte_ *data;
}Record;

typedef struct
{
    char subType[4];
    ushort_ dataSize;
    ubyte_ *data;
}SubRecord;

typedef struct
{
    char type[4];
    ushort_ groupSize;
    ubyte_ label[4];
    long_ groupType;
    ulong_ stamp;
}Group;

#endif // TES4FILEESMPSTRUCTS_H
