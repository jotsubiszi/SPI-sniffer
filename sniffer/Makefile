TARGET=sniffer

SRC=pinConf.c spiSniffing.c uarting.c main.c
OBJ=$(SRC:.c=.o)

CC=avr-gcc
MCU=atmega328p

CFLAGS=-mmcu=$(MCU) -std=c99 -Werror -Wall

TOOLS_DIR=tools
COMPILE_COMMANDS=compile_commands.json

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -rf *.o *.elf
