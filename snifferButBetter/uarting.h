#include <avr/io.h>
#include <stdio.h>

#define USART0_CLOCK_HZ 1000000
#define BAUD_RATE_HZ 9600
#define UBRR_VALUE (USART0_CLOCK_HZ / BAUD_RATE_HZ)

int USART_tx(char, struct __file *_f);

void USART0_init(void);
