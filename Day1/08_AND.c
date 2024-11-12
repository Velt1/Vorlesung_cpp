#include <stdio.h>

const int IS_SU = 0x1;
const int HAVE_WRITE = 0x2;
const int HAVE_DELETE = 0x4;
const int HAVE_READ = 0x8;

int main(void)
{
  int rechte = 0;

  rechte = rechte | HAVE_READ;
  printf("Rechte nach HAVE_READ %d\n", rechte);
  rechte = rechte | HAVE_WRITE;
  printf("Rechte nach HAVE_WRITE %d\n", rechte);
  printf("Prüfe Recht IS_SU ");
  if ((rechte & IS_SU) == IS_SU) printf("ja\n"); else printf("nein\n");
  return 0;
}
