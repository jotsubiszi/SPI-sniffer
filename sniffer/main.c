#include "pinConf.h"
#include "uarting.h"
#include <avr/common.h>
#include <avr/interrupt.h>
#include <stdint.h>

uint8_t flag;

ISR(INT1_vect) { flag = 1; }

int main(void) {
  pinsInit();
  USART0_init();
  sei();

  EICRA = 0b00001000;
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

    if (counter >= 8) {
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
