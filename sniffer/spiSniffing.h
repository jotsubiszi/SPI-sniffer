#include "pinConf.h"
#include <stdint.h>

typedef struct {

  char tabINT[32];

  uint8_t INTCharCounter;

  uint8_t INTTabCounter;

  uint8_t INTChar;

} sniffin;

void sniffMosi(sniffin *snif);
void sniffMiso(sniffin *snif);

void sniffAll(sniffin *MISO, sniffin *MOSI);
