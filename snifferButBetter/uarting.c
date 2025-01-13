#include "uarting.h"

int USART0_tx(char data, struct __file *_f) {
  while (!(UCSR0A & (1 << UDRE0)))
    ;
  UDR0 = data;
  return 0;
}

static FILE uartout = FDEV_SETUP_STREAM(USART0_tx, NULL, _FDEV_SETUP_WRITE);

void USART0_init(void) {
  UBRR0H = (UBRR_VALUE >> 8) & 0xF;
  UBRR0L = UBRR_VALUE & 0xFF;
  UCSR0B = 1 << TXEN0;
  UCSR0C = 3 << UCSZ00;
  stdout = &uartout;
}
