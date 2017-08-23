#include "tes4fileesmp.h"

TES4FileESMP::TES4FileESMP(std::string f)
{
    this->filename = f;
}

void TES4FileESMP::read()
{
    unsigned int i,j;

    std::ifstream file;
    file.open(filename, std::ifstream::binary);

    auto readRecord = [&]() -> Record
    {
        Record r;

        file.read(r.type,4);
        file.read((char*) (&r.dataSize), sizeof(r.dataSize));
        file.read((char*) (&r.flags), sizeof(r.flags));
        file.read((char*) (&r.formid), sizeof(r.formid));
        file.read((char*) (&r.versionControlInfo), sizeof(r.versionControlInfo));
        r.data = (ubyte_*) malloc(r.dataSize);
        file.read((char*) (r.data), r.dataSize);

        return r;
    };

    Record TES4 = readRecord();

    // DLCShiveringIsles.esp
    if(file.peek() == EOF)
        return;

    Group g;

    file.read(g.type,4);
    file.read((char*) (&g.groupSize), sizeof(g.groupSize));
    file.read((char*) g.label,4);
    file.read((char*) (&g.groupType), sizeof(g.groupType));
    file.read((char*) (&g.stamp), sizeof(g.stamp));

    std::cout << g.groupSize << std::endl;

    char* tmp = (char*) malloc(g.groupSize-20);
    file.read(tmp,g.groupSize-20);


    for(i=0;i<g.groupSize-20;i++)
        std::cout << tmp[i];
    std::cout << tmp << std::endl;

    file.read(g.type,4);
    std::cout << g.type << std::endl;

    /*
    for(i=0;i<TES4.dataSize;i++)
        std::cout << TES4.data[i];
    std::cout << std::endl;
    char tmp[4];
    file.read(tmp,4);
    */

    file.close();
}
