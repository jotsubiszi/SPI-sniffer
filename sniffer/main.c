#include "pinConf.h"
#include "uarting.h"
#include <avr/common.h>
#include <avr/interrupt.h>
#include <stdint.h>

uint8_t flag;

ISR(INT1_vect) { flag = 1; }

// The interrupt execution response for all the enabled AVR® interrupts is four
// clock cycles minimum

int main(void) {
  pinsInit();
  USART0_init();
  sei();
  // The I-bit is cleared by hardware after an interrupt has occurred, and
  // is set by the RETI instruction to enable subsequent interrupts.
  // The I-bit can also be set and cleared by the application with the
  // SEI and CLI instructions, as described in the instruction set reference.
  EICRA = 0b00001000;
  // INT0 on rising
  // INT1 on falling
  EIMSK = 0b00000010;
  uint8_t counter = 0;
  uint8_t shiftMiso = 0;
  uint8_t shiftMosi = 0;

  printf("%i\r\n", shiftMiso);
  while (1) {
    if (flag > 0) {
      shiftMiso = (shiftMiso << 1) + readPinMISO();
      shiftMosi = (shiftMosi << 1) + readPinMOSI();
      printf("bit rec!\r\n");
      counter++;
      flag = 0;
    }

    if (counter == 8) {
      printf("MISO: %i\r\n", shiftMiso);
      printf("MOSI: %i\r\n", shiftMosi);
      counter = 0;
      flag = 0;
      shiftMiso = 0;
      shiftMosi = 0;
    }
  }
  return 0;
}
