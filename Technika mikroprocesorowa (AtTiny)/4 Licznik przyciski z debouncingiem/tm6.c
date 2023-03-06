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
    uint8_t stan=0;
    uint8_t btn_before, btn_current;
    uint8_t limit=10;
    uint8_t debounce_cnt=0;
    
    DDRA &= (1<<SW1);
    DDRB &= (1<<SW2);
    DDRA = (1<<RED1) | (1<<YEL1) | (1<<GRN1) | (1<<RED2) | (1<<YEL2) | (1<<GRN2);
    PUEA |= (1<<SW1); //INICJACJA
    PUEB |= (1<<SW2);
    PORTA |= (1<<SW1);
    PORTA |= (1<<SW2);
    
    //btn_before=btn_current;
    btn_current=SW1;
    
    
    while(1)
    {
    if(stan==0)
    {
        if(btn_before!=btn_current)
        {
            stan=1;
        }
    }
    else if(stan==1)
    {
        if(btn_before==btn_current)
        {
            if(debounce_cnt>=limit)
            {
                stan=2;
                counter++;
            }
            else
            {
                debounce_cnt++;
            }
        }
        else
        {
            stan=0;
            btn_before=btn_current;
            debounce_cnt=0;
        }
        
    }
    else if(stan==2)
    {
        if(btn_before!=btn_current)
        {
            stan=0;
            btn_before=btn_current;
            debounce_cnt=0;
        }
    }
    
    PORTA=counter;
    }
    
    
    
    
    
    
    
    /*
    while(1)
    {
        if (!(PINA & (1<<SW1)))
        {
            counter++;
        }
        
        if (!(PINB & (1<<SW2)))
        {
            counter--;
        }
        
        if(counter==64)
        {
            counter=0;
        }
        
        PORTA=counter;
        
    }
    */


}
 
