#include <avr/io.h>
#include <avr/interrupt.h>

#define RED1 PORTA1
#define YEL1 PORTA2
#define GRN1 PORTA3
#define RED2 PORTA4
#define YEL2 PORTA5
#define GRN2 PORTA6
#define SW1 PINA7
#define SW2 PINB0


int main(void)
{    
    uint8_t counter=32;
    
    DDRA &= (1<<SW1);
    DDRB &= (1<<SW2);
    DDRA = (1<<RED1) | (1<<YEL1) | (1<<GRN1) | (1<<RED2) | (1<<YEL2) | (1<<GRN2);
    PUEA |= (1<<SW1); //INICJACJA
    PUEB |= (1<<SW2);
    PORTA |= (1<<SW1);
    PORTA |= (1<<SW2);
    
    while(1)
    {
        if(!(PINA & 1<<PINA7))
        {
        //counter++;
        //PORTA = (1<<RED1) | (1<<YEL1) | (1<<GRN1) | (1<<RED2) | (1<<YEL2) | (1<<GRN2);
        PORTA=counter;
        }
        else
        {
        PORTA = (0<<RED1) | (0<<YEL1) | (0<<GRN1) | (0<<RED2) | (0<<YEL2) | (0<<GRN2);
        }
        
        
        
    }
    


}
 
