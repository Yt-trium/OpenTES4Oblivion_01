# OpenTES4Oblivion documentations

## Table of contents

* [File format](#file-format)
  * [The Elder Scrolls file format](#the-elder-scrolls-file-format)
  * [Other file format](#other-file-format)
  * [Types information](#types-information)
* [About](#about)

## File format

### The Elder Scrolls file format

* [BSA](bsa.md)
* [ESM](esm.md)
* [ESP](esp.md)

### Other file format

* [BIK](bik.md)

### Types information

*typename (size in bytes) : description*

* char (1) : character
* short (2) : signed short integer
* ushort (2) : unsigned short integer
* long (4) : signed long integer
* ulong (4) : unsigned long integer

* zstring (?) : string terminated with a zero.
* bstring (1+?) : string prefixed with length (byte) and not terminated with a zero.
* bzstring (1+?) : string prefixed with length (byte) and terminated with a zero.

## About

This documentation is based on test performed on the TES4 originals (FR version) files.
Many informations has been found on website, wikis and forums.

* uesp.net wiki (bsa/esm/esp file format)
* wikipedia.org (bik file format)