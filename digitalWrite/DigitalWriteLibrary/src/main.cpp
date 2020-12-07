#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
 
int main(void)
{
  PORTB &= ~(1 << 2);

  for(;;)
  {
    PORTD |= (1 << 3);
    PORTD &= ~(1 << 2);
    // PORTB &= ~(1 << 2);
    _delay_ms(500);
    PORTD &= ~(1 << 3);
    PORTB |= (1 << 2);
    PORTD |= (1 << 2);
    _delay_ms(500);
  }
}
