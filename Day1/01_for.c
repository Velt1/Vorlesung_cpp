#include<stdio.h>

int main(void)
{
  short i=0; // lokale Variable mit 16 Bit (2Bytes)

  for (;i<10;i++) {
    printf("Ausgabe %d %d\n", i, (i*i));
  }
  return 0;
}
