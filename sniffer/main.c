#include "pinConf.h"
#include <avr/common.h>
#include <avr/interrupt.h>

ISR(INT0_vect) {}

ISR(INT1_vect) {}

// The interrupt execution response for all the enabled AVR® interrupts is four
// clock cycles minimum

int main(void) {

  pinsInit();
  sei();
  // The I-bit is cleared by hardware after an interrupt has occurred, and
  // is set by the RETI instruction to enable subsequent interrupts.
  // The I-bit can also be set and cleared by the application with the
  // SEI and CLI instructions, as described in the instruction set reference.
  EICRA = 0b00001011;
  // INT0 on rising
  // INT1 on falling
  EIMSK = 0b00000011;
  return 0;
}
