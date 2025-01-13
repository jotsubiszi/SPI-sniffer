#include "pinConf.h"

void pinsInit() {
  DDRD &= ~(1 << PD2);
  DDRD &= ~(1 << PD3);
  // PD2 = INT0
  // PD3 = INT1
  PORTD &= ~(1 << PD2);
  PORTD &= ~(1 << PD3);

  DDRB = 0b00000000;
  PORTB = 0b00000000;
}

uint8_t readPort() { return PINB; }
