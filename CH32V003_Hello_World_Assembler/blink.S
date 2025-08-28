#include "ch32fun.h"

// Resources:
// - https://msyksphinz-self.github.io/riscv-isadoc/
// - https://en.wikipedia.org/wiki/RISC-V_instruction_listings

// Config:
//  LED - PA1

    .global main

main:
    // RCC->APB2PCENR = RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA
    li a0, RCC_BASE
    lw a1, 0x18(a0)
    ori a1, a1, (0x00000001 | 0x00000004)
    sw a1, 0x18(a0)

    // GPIOA->CFGLR |= 0x10
    li a0, GPIOA_BASE
    lw a1, 0x0(a0)
    andi a1, a1, 0xFFFFFF0F
    ori a1, a1, 0x10
    sw a1, 0x0(a0)

loop:
    // Turn LED on.
    // GPIOA->BSHR = 0x2
    li a0, GPIOA_BASE
    lw a1, 0x10(a0)
    ori a1, a1, 0x02
    sw a1, 0x10(a0)

    call delay

    // Turn LED off.
    // GPIOA->BSHR = 0x020000
    li a0, GPIOA_BASE
    lw a1, 0x10(a0)
    li a2, 0x20000
    or a1, a1, a2
    sw a1, 0x10(a0)

    call delay
    
    j loop

delay:
    li a0, 0
    li a1, 1000000
delay_loop:
    addi a0, a0, 1
    bne a0, a1, delay_loop
    ret
