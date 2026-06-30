/*Prolem 1: Macro define */
#include <stdio.h>
#include <stdint.h>

uint32_t set_bit(uint32_t var, uint8_t pos)
{
    if(pos < 0 || pos > 31)
    {
        return var;
    }
    var |= (1 << pos);
    return var;
}

uint32_t clear_bit(uint32_t var, uint8_t pos)
{
    if(pos < 0 || pos > 31)
    {
        return var;
    }
    var &= ~(1 << pos);
    return var;
}

uint32_t toggle_bit(uint32_t var, uint8_t pos)
{
    if(pos < 0 || pos > 31)
    {
        return var;
    }
    var ^= (1 << pos);
    return var;

}
int main(void)
{
    uint32_t x = 0x00000005; /* 000...0101 */
    printf("Origin: 0x%08x\n", x);
    printf("Set bit 1: 0x%08x\n", set_bit(x, 1)); /* 000...0111 */
    printf("clear bit 1: 0x%08x\n", clear_bit(x, 1)); /* 000...0101*/
    printf("Toggle bit 1 0x%08x\n", toggle_bit(x, 1)); /* 000...0111 */
    return 0;
}