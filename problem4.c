/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

#define REG_ADRR    ((volatile uint32_t*)(0x20250000))
typedef union
{
    uint32_t packed_value;   
    struct
    {
        uint32_t input_clk_frequency : 11; /* 11bits [10-0]*/
        uint32_t clk_dev_ratio       : 8;  /* 8bits  [18:11]*/
        uint32_t clk_mul_ratio       : 8;  /* 8bits  [26:19]*/
        uint32_t reserved            : 5;  /* 5bits  [31:27]*/
    }clk_cfg;
}clk_reg_t;

static inline void writel(uint32_t value, volatile uint32_t *reg_adrr)
{
    *(volatile uint32_t*)reg_adrr = value;
}

int main()
{
    printf("Hello World\n");
    clk_reg_t reg;
    
    reg.packed_value = 0;
    reg.clk_cfg.input_clk_frequency = 100;
    reg.clk_cfg.clk_dev_ratio       = 3;
    reg.clk_cfg.clk_dev_ratio       = 2;
    
    printf("Packed value: 0x%08x\n", reg.packed_value);
    
    writel(reg.packed_value, REG_ADRR);

    return 0;
}