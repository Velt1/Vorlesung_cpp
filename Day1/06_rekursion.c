#include <stdio.h>

int rek(int i)
{
  printf("v: %d\n",i);
  if (i>=10) return 0;
  else rek(++i);
  printf("n: %d\n",i);
}

int main(void)
{
  rek(0);
}
