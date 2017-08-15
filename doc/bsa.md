# BSA File Format

## Table of contents

* [File Structure](#file-structure)
* [Information about types](#information-about-types)
* [About](#about)

## File Structure

* [header](#header)
* List of [folderRecords](#folderrecords) (folderCount items)
* List of [fileRecordBlocks](#filerecordblocks) (folderCount * [folderRecords](#folderrecords).count items)
* List of filename [fileNameBlock](#filenameblock) (fileCount items)
* [files](#files)

### header

* fileId (char[4])
* version (32bit unsigned int)
* offset (32bit unsigned int)
* archiveFlags (32bit unsigned int) (bits 1, 2, 9, 10, 11 are set in all official BSA files) (bits 4, 5, 6, 8 has no effect on the file structure)
  * bit 1 - Archive has names for directories
  * bit 2 - Archive has names for files
  * bit 3 - Files are by default compressed
  * bit 4 - Unknown
  * bit 5 - Unknown
  * bit 6 - Unknown
  * bit 7 - Xbox360 archive
  * bit 8 - Unknown
  * bit 9 - Unknown
  * bit 10 - Unknown
  * bit 11 - Unknown
* folderCount (32bit unsigned int)
* fileCount (32bit unsigned int)
* totalFolderNameLength (32bit unsigned int)
* totalFileNameLength (32bit unsigned int)
* fileFlags (32bit unsigned int)
  * bit 1 - Meshes
  * bit 2 - Textures
  * bit 3 - Menus
  * bit 4 - Sounds
  * bit 5 - Voices
  * bit 6 - Shaders
  * bit 7 - Trees
  * bit 8 - Fonts
  * bit 9 - Miscellaneous

### folderRecords
* nameHash (64bit hash of string)
* count (32bit unsigned int)
* offset (32bit unsigned int)

### fileRecordBlocks

##### bit 1 of archive flags is set
* name (bzstring)
* [fileRecords](#filerecord)

##### bit 1 of archive flags is not set
* [fileRecords](#filerecord)

####  fileRecord
* nameHash (64bit hash of string)
* size (32bit unsigned int)
* offset (32bit unsigned int)

### fileNameBlock
(archive flag 2 is set)
* List of lower case file names, one after another (ending with a 0) ordered in the same order as those generated with the fileRecord's fileRecordBlocks.

### files

The files are listed in the fileRecord and the data are stored after the offset address.

#### uncompressed file block
* originalSize (32bit unsigned int)
* data[size] (8bit)

#### compressed file block
* data[size] (8bit)

uesp.net wiki information : if bit 9 of archiveFlags is set, the file data blocks begin with a bstring containing the full path of the file (not tested yet, more information soon).

## Information about types

* bstring : string prefixed with length (byte) and not terminated with a zero.
* bzstring : string prefixed with length (byte) and terminated with a zero.

## About

This documentation is based on the uesp.net wiki information about the bsa file format and the test performed on the TES4 originals bsa files.
