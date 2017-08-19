#ifndef TES4FILESTYPES_H
#define TES4FILESTYPES_H

typedef int8_t   byte_;
typedef uint8_t  ubyte_;
typedef int16_t  short_;
typedef uint16_t ushort_;
typedef int32_t  long_;
typedef uint32_t ulong_;

typedef struct
{
    char* string;
}Zstring;

typedef struct
{
    uint8_t length;
    char* string;
}Bstring;

typedef struct
{
    uint8_t length;
    char* string;
}BZstring;

#endif // TES4FILESTYPES_H
