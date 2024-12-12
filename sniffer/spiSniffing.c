#include "pinConf.h"
#include <stdint.h>

typedef struct {

  char tabINT[32];

  uint8_t INTCharCounter;

  uint8_t INTTabCounter;

  uint8_t INTChar;

} sniffin;

void sniffMosi(sniffin *snif) {
  uint8_t sniffedINTBit = readPinMOSI();
  snif->INTChar = snif->INTChar << 1;
  snif->INTChar |= sniffedINTBit << 0;
  snif->INTCharCounter++;
  if (snif->INTCharCounter >= 8) {
    snif->INTCharCounter = 0;
    snif->tabINT[snif->INTTabCounter] = snif->INTChar;
    snif->INTTabCounter++;
  }
}

void sniffMiso(sniffin *snif) {
  uint8_t sniffedINTBit = readPinMISO();
  snif->INTChar = snif->INTChar << 1;
  snif->INTChar |= sniffedINTBit << 0;
  snif->INTCharCounter++;
  if (snif->INTCharCounter >= 8) {
    snif->INTCharCounter = 0;
    snif->tabINT[snif->INTTabCounter] = snif->INTChar;
    snif->INTTabCounter++;
  }
}

void sniffAll(sniffin *MISO, sniffin *MOSI) {
  sniffMiso(MISO);
  sniffMosi(MOSI);
}
