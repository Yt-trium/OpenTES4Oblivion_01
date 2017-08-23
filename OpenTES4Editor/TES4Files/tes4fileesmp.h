#ifndef TES4FILEESMP_H
#define TES4FILEESMP_H

#include "tes4files.h"
#include "tes4fileesmpstructs.h"

class TES4FileESMP
{
public:
    TES4FileESMP(std::string f);

    void read();
private:
    std::string filename;
};

#endif // TES4FILEESMP_H
