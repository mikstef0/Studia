/*
 * projekt2.c
 *
 * Created: 03.12.2021 15:01:45
 * Author : Student
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define R1 PORTA0
#define Y1 PORTA1
#define G1 PORTA3
#define R2 PORTA4
#define Y2 PORTA5
#define G2 PORTA6

volatile int i=1;


ISR (TIM0_COMPA_vect)
{
    i++;
    if(i>40) i=0;
}


int main(void)
{    
    TCCR0A = 0;
    TCCR0B = 0;
    
    OCR0A = 200;
    
    TCCR0B |= (1<<WGM02);
    
    TCCR0B |= ((1<<CS00) | 1<<CS02 );
    
    TIMSK0 |= (1<<OCIE0A);
    
    DDRA = (1<<R1) | (1 <<Y1) | (1<<G1) | (1<<R2) | (1 <<Y2) | (1<<G2);
    //PORTB = (1<<RED1) | (0 <<YEL1) | (0<<GRN1);
    
    while(1)
    {
        

    switch(i) {
        
        case 1 ... 5:
        PORTA = (1<<R1) | (0 <<Y1) | (0<<G1) | (1<<R2) | (0 <<Y2) | (0<<G2); break;
        
        case 6 ... 10:
        PORTA = (1<<R1) | (1 <<Y1) | (0<<G1) | (1<<R2) | (0 <<Y2) | (0<<G2); break;
        
        case 11 ... 15:
        PORTA = (0<<R1) | (0 <<Y1) | (1<<G1) | (1<<R2) | (0 <<Y2) | (0<<G2); break;
        
        case 16 ... 20:
        PORTA = (0<<R1) | (1 <<Y1) | (0<<G1) | (1<<R2) | (0 <<Y2) | (0<<G2); break;
        
        case 21 ... 25:
        PORTA = (1<<R1) | (0 <<Y1) | (0<<G1) | (1<<R2) | (0 <<Y2) | (0<<G2); break;
        
        case 26 ... 30:
        PORTA = (1<<R1) | (0 <<Y1) | (0<<G1) | (1<<R2) | (1 <<Y2) | (0<<G2); break;
        
        case 31 ... 35:
        PORTA = (1<<R1) | (0 <<Y1) | (0<<G1) | (0<<R2) | (0<<Y2) | (1<<G2); break;
        
        case 36 ... 40:
        PORTA = (1<<R1) | (0 <<Y1) | (0<<G1) | (0<<R2) | (1 <<Y2) | (0<<G2); break;
        
        default:
        i=1; break;
        
    }
    
    sei();
    
    }
    
    
//    while (1);


} 
