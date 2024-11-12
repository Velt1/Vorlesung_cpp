#include <stdio.h>

int main(void)
{
  int i= 5;
  float f = 4.0;
  double d = 5.7;

  printf("int mit d: %d, mit lf floating vars: l: %lf, d:%lf\n",i,f,d);
  printf("%10lf | %-10lf\n",f,f);
  printf("%10lf | %-10lf\n",f,f);
  return 0;
}
