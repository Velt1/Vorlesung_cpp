#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print_array(char *s)
{
    int i=0;
    while (s[i]!='\0') 
    {
        printf("Zeichen %d ist %c\n",i,s[i]);
        i++;
    }
    printf("Abbruch Zeichen %d ist %c\n",i,s[i]);
}
int main(void)
{
    char *s1 = NULL;
    
    /* Speicher reservieren */
    s1 = (char *) malloc(sizeof(char) * 16);
    /* Verarbeiten und Ausgeben */
    strcpy(s1,"Student");

    printf("S1: [%s]\n", s1);
    printf("Array: \n");
    print_array(s1);

    /* Speicher freigeben */
    free(s1); /* Auch Abhilfe beim finden von use after free */
    return 0;
}
