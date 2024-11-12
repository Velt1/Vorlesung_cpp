#include<stdio.h>

void printout(char s[], int l)
{
    int i=0;
    for(i=0;i<l;i++) printf("%c",s[i]);
    printf("\n");
}
void printout_array(char s[], int l)
{
    int i=0;
    for(i=0;i<l;i++) printf("%c (D: %d)",s[i], s[i] );
}

int main(void)
{
    char s[10];

    s[0] = 'S';
    s[1] = 't';
    s[2] = 'u';
    s[3] = 'd';
    s[4] = 'e';
    s[5] = 'n';
    s[6] = 't';

    printout(s,10);
    printout_array(s,10);
 
    return 0;
}
