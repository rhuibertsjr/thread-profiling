#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define internal static

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define KB(b) ((b) << 10)
#define MB(b) ((b) << 20)

#endif // BASE_H
