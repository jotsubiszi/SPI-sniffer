#include <avr/common.h>
#include <avr/interrupt.h>
#include <avr/io.h>

void interruptINIT() {
  SREG = 0b10000000;
  // The I-bit is cleared by hardware after an interrupt has occurred, and
  // is set by the RETI instruction to enable subsequent interrupts.
  // The I-bit can also be set and cleared by the application with the
  // SEI and CLI instructions, as described in the instruction set reference.
  EICRA = 0b00000101;
  EIMSK = 0b00000011;
}

ISR(INT0_vect) {}

ISR(INT1_vect) {}

// The interrupt execution response for all the enabled AVR® interrupts is four
// clock cycles minimum
