#include <stdio.h>

int main(void)
{
  int a = 10000;
  int i;
  int j;
  long counter = 0;
  int is_prime;
  for (i=2;i<a;i++) {
    is_prime=1;
    for (j=2;j<i;j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      counter++;
      printf("Das ist eine Primzahl: %d\n",i);
    }
  }
  printf("Counter: %ld\n", counter);
  return 0;
}
