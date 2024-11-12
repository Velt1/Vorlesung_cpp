#include<stdio.h>

int main(void)
{
  short i = 32766;
  printf("32766: %d\n",i);
  i++;
  printf("32767: %d\n",i);
  i++;
  printf("32768: %d\n",i);
  i++;
  printf("32769: %d\n",i);
}
