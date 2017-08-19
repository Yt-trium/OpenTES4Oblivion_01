# BSA File Format

The BSA are Bethesda Softworks Archive files.

## File Structure

* [header](#header)
* List of [folderRecords](#folderrecords) (folderCount items)
* List of [fileRecordBlocks](#filerecordblocks) (folderCount * [folderRecords](#folderrecords).count items)
* List of filename [fileNameBlock](#filenameblock) (fileCount items)
* [files](#files)

### header

* fileId (char[4])
* version (ulong)
* offset (ulong)
* archiveFlags (ulong) (bits 1, 2, 9, 10, 11 are set in all official BSA files) (bits 4, 5, 6, 8 has no effect on the file structure)
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
* folderCount (ulong)
* fileCount (ulong)
* totalFolderNameLength (ulong)
* totalFileNameLength (ulong)
* fileFlags (ulong)
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
* nameHash (bsa hash of string 8 bytes)
* count (ulong)
* offset (ulong)

### fileRecordBlocks

##### bit 1 of archive flags is set
* name (bzstring)
* [fileRecords](#filerecord)

##### bit 1 of archive flags is not set
* [fileRecords](#filerecord)

####  fileRecord
* nameHash (bsa hash of string 8 bytes)
* size (ulong)
* offset (ulong)

### fileNameBlock
(archive flag 2 is set)
* List of lower case file names, one after another (ending with a 0) ordered in the same order as those generated with the fileRecord's fileRecordBlocks.

### files

The files are listed in the fileRecord and the data are stored after the offset address.

#### uncompressed file block
* originalSize (ulong)
* data[size] (char[size])

#### compressed file block
* data[size] (char[size])
