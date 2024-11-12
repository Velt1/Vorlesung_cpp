#include <stdio.h>

void isbit(int i)
{
  if (i==0) return;
  int c = i % 2;
  int t = i/2;
  isbit(t);
  printf("%d", c);
}

int main(void)
{
  int i;
  printf("Bitte eine Zahl eingeben: ");
  scanf("%d", &i);
  isbit(i);
  printf("\n");
  //Zahl in BITS ausgeben - bei 25 z.B. 11001
  
  return 0;
}
