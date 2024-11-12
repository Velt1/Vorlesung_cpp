#include <stdio.h>

int main(void)
{
  int i[10] = {1,3,5,8,6,4,234,5235,32,24};

  int z;
  for (z=0;z<10;z++) {
    printf("i[%2d]: %4d\n", z,i[z]);
  }
}
