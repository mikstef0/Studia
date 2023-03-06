.thumb	// Cortex-M4 works in THUMB mode, check whether it is required

// RM0316 - Reference Manual - STM32F303xB/C/D/E (...) advanced ARM-based MCUs
.equ PERIPHERAL_BASE,	(0x40000000)
.equ AHB_OFFSET,		(0x00020000)
.equ AHB2_OFFSET,		(0x08000000)
.equ RCC_OFFSET,		(0x00001000)
.equ GPIOA_OFFSET,		(0x00000000)
.equ GPIOB_OFFSET,		(0x00000400)
.equ GPIOC_OFFSET,		(0x00000800)
.equ RCC_AHBENR_OFFSET,	(0x00000014)	// AHB peripheral clock enable register (RCC_AHBENR)

.equ AHB_BASE,			(PERIPHERAL_BASE + AHB_OFFSET)
.equ AHB2_BASE,			(PERIPHERAL_BASE + AHB2_OFFSET)

.equ RCC_BASE,			(AHB_BASE + RCC_OFFSET)		// Reset and Control Clock

.equ GPIOA_BASE,		(AHB2_BASE + GPIOA_OFFSET)	// Port A base
.equ GPIOB_BASE,		(AHB2_BASE + GPIOB_OFFSET)	// Port B base
.equ GPIOC_BASE,		(AHB2_BASE + GPIOC_OFFSET)	// Port C base

// Set main faunction as global for linker
.global main

@ Vector table
.word               0x20001000	@ Vector #0 - Stack pointer init value (0x20000000 is RAM address and 0x1000 is 4kB size, stack grows "downwards")
.word               main        @ Vector #1 - Reset vector - where the code begins
                                @ Vector #3..#n - I don't use Systick and another interrupts right now
                                @                so it is not necessary to define them and code can start here

.thumb_func                		@ Force the assembler to call this function in Thumb mode, that means the least significant bit in address is set
                        		@ Using this bit, the ARM core knows whether is jumping to the ARM or Thumb code, Cortex supports only Thumb
                        		@ Also you can use ".type    _start, %function"
main:

    @ Enable clock for GPIOC peripheral in RCC registers
    @LDR r0, =(RCC_BASE + 0x14)
    @ Enable clock for GPIOC peripheral in RCC registers
    LDR r0, =(RCC_BASE + RCC_AHBENR_OFFSET)
    LDR r1, =(1 << 17)
    STR r1, [r0]     @Store R0 value to r1

    @ Enable GPIOC pin 9 as output
    @ Enable GPIOA pin 5 as output
    LDR r0, =(GPIOA_BASE + 0x00)
    LDR r1, =(1 << (5*2))    @ Every bin has 2 bit settings, hence *2
    STR r1, [r0]     @Store R0 value to r1


loop:

    @ Write high to pin PC9
    @ Write high to pin PA5
    LDR r0, =(GPIOA_BASE + 0x14)
    LDR r1, =(1 << 5)
    @LDR r1, =32
    STR r1, [r0]     @Store R1 value to address pointed by R0

    @ Dummy counter to slow down my loop
    LDR R0, =0
    LDR R1, =400000

loop0:
    ADD R0, R0, #1
    cmp R0, R1
    bne loop0

    @ Write low to PC9
    @ Write low to PA5
    LDR r0, =(GPIOA_BASE + 0x14)
    LDR r1, =(0)
    STR r1, [r0]     @Store R1 value to address pointed by R0

    @ Dummy counter to slow down my loop
    LDR R0, =0
    LDR R1, =400000

loop1:
    ADD R0, R0, #1
    cmp R0, R1
    bne loop1

	b loop
