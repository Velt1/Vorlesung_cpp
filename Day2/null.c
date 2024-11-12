#include<stdio.h>
#include<string.h> /*strcpy, strcat */

void print_array(char s[])
{
    int i=0;
    while (s[i]!='\0')
    {
        printf("Zeichen an Stelle %i ist: [%c]\n",i,s[i]);
        i++;
    }
    printf("Abbruch war an Stelle %i \n", i);
}
int main(void)
{
    /* Statischer Speicher */
    char s1[16];

    /* Schreiben in den Speicher */
    strcpy(s1,"Student");

    /*Ausgabe*/
    printf("S1: [%s]\n",s1);
    print_array(s1);

    return 0;
}
