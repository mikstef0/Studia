;
; projekt.asm
;
; Created: 26.11.2021 14:59:43
; Author : Student
;


; Replace with your application code
/*start:
    inc r16
    rjmp start */

.include "tn104def.inc"
 .ORG 0
 LDI R16, (1<<PORTB3)|(1<<PORTB2)|(1<<PORTB1)
 OUT DDRB, R16

 LDI R17, 0
 LDI R18, 0xD8
 OUT CCP, R18
 OUT CLKPSR, R17


 start:
 OUT PORTB, R16
 ;COM R16
 RCALL dilej
 COM R16
 RJMP start

 dilej: ; 500 000 cykli 1+255(1+2) = 766 cykli
 LDI R19, 4
 loop3:

 LDI R18, 162
 loop2:

 LDI R17, 255 ; 1 cykl
 loop1:
 DEC R17 ; 1 cykl
 BRNE loop1 ; 2 cykle ;skok do loop1 jeśli wynik DEC R17 był 0
 
 DEC R18 ; 1 cykl
 BRNE loop2 ; 2 cykle

 DEC R19
 BRNE loop3
 
 RET
 
 
 RET 
