#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_big_endian(void)
{
    uint32_t x = 0x01020304;
    
    uint8_t *p = (uint8_t *)&x;
    return (*p == 0x01);
}

uint16_t swap16(uint16_t value)
{
    return (value >> 8) | (value << 8);
}

/*
 * 0x11223344 -> 0x44332211
 * [31-0] : 44 << 24 | 33 << 8 | 22 >> 8 | 11 >> 24
 */
uint32_t swap32(uint32_t value)
{
    return ((value & 0x000000FFU) << 24) |
           ((value & 0x0000FF00U) << 8)  |
           ((value & 0x00FF0000U) >> 8)  |
           ((value & 0xFF000000U) >> 24);
}


int main()
{
    printf("Is big endian: %d\n", is_big_endian());
    
    uint16_t x = 0x1234;
    printf("before swap16: 0x%08x\n", x);
    printf("after swap16: 0x%08x\n", swap16(x));
    
    uint32_t y = 0x11223344;
    printf("before swap32: 0x%08x\n", y);
    printf("after swap32: 0x%08x\n", swap32(y));
    return 0;
}