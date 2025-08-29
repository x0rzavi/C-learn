#include <stdio.h>
#include <stdlib.h>

int main(void) {
  typedef union unsignedInspect unsignedInspect;
  union unsignedInspect {
    unsigned val;
    unsigned char bytes[sizeof(unsigned)];
  };

  unsignedInspect twofold = {.val = 0xAABBCCDD};

  printf("value is 0x%.08X\n", twofold.val);
  for (size_t i = 0; i < sizeof twofold.bytes; ++i) {
    printf("byte[%zu]: 0x%.02hhX\n", i, twofold.bytes[i]);
  }
  return EXIT_SUCCESS;
}
