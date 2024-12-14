#include "spiSniffing.h"
#include <avr/common.h>
#include <avr/interrupt.h>

sniffin MISO;
sniffin MOSI;

ISR(INT0_vect) { sniffMiso(&MISO); }

ISR(INT1_vect) { sniffMosi(&MOSI); }

// The interrupt execution response for all the enabled AVR® interrupts is four
// clock cycles minimum

int main(void) {
  pinsInit();

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

  while (1 == 1) {
  }
  return 0;
}
