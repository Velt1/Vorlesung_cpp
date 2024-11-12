#include <stdio.h>

int plus(int a, int b)
{
  int c = a + b;
  return c;
}

int main(void)
{
  int a = 4;
  int b = 5;
  int c = plus(a,b);
  printf("a (%d) + b (%d) = c (%d)\n", a,b,c);
  return 0;
}
