#include "pinConf.h"

void pinsInit() {
  DDRD &= ~(1 << PD2);
  DDRD &= ~(1 << PD3);
  // PD2 = INT0
  // PD3 = INT1
  PORTD &= ~(1 << PD2);
  PORTD &= ~(1 << PD3);

  DDRD &= ~(1 << PD4);
  DDRD &= ~(1 << PD5);
  // PD4 = MISO
  // PD5 = MOSI
  PORTD &= ~(1 << PD4);
  PORTD &= ~(1 << PD5);
}

uint8_t readPinMISO() { return (PIND & (1 << PD4)) == 0 ? 0 : 1; }

uint8_t readPinMOSI() { return (PIND & (1 << PD5)) == 0 ? 0 : 1; }
