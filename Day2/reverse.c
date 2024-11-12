#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse(char *s)
{
    int len = strlen(s);
    char *temp = (char *)malloc(sizeof(char)*(len+1));
    int i = 0;

    s+=len-1;
    while (i<len) 
    {
        *temp =  *s;
        temp++;
        s--;
    }
    temp[len] = '\0';
    strcpy(s,temp);
    free(temp);
}

int main(void)
{
 char *s1 = (char *)malloc(sizeof(char));
}
