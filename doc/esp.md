# ESP File Format

The ESP are Elder Scrolls Plugin files.

## File Structure

ESP files are composed of records, which are divided into subrecords. The records are themselfs stored into groups by GRUP records.

At the beginning, the file is :
* A [TES4](esp_tes4.md) record which contain the file information.
* A collection of groups.

#### Records

* type (char[4])
* dataSize (ulong)
* flags (ulong)
* formid (ulong)
* versionControlInfo (ulong)
* data (ubyte[dataSize])

#### SubRecords
* subType (char[4])
* dataSize (ushort)
* data (ubyte[dataSize])

## Record Types

* [TES4](esp_tes4.md)