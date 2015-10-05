#pragma once

typedef char int8;
typedef unsigned char uint8;

typedef short int16;
typedef unsigned short uint16;

typedef int int32;
typedef unsigned int uint32;

typedef long int64;
typedef unsigned long uint64;

template<typename first_type, typename second_type>
struct pair_type
{
    first_type first;
    second_type second;
    pair_type(first_type f, second_type s) : first(f), second(s) {}
};

#define LOGGING_EXTRA
//#define LOGGING_MIMINAL