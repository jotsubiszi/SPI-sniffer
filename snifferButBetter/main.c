#include "pinConf.h"
#include "uarting.h"
#include <avr/common.h>
#include <avr/interrupt.h>
#include <stdint.h>

uint8_t flag;

ISR(INT1_vect) { flag += 1; }

int main(void) {
  pinsInit();
  USART0_init();
  sei();

  EICRA = 0b00001000;
  EIMSK = 0b00000010;

  while (1) {
    if (flag >= 8) {
      printf("%i", readPort());
      flag = 0;
    }
  }
  return 0;
}
