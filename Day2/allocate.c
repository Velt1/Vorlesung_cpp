#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    char *s1 = NULL, *s2 = NULL, *s3 = NULL;
    s1 = (char *)malloc(sizeof(char)*16);
    s2 = (char *)malloc(sizeof(char)*16);
    s3 = (char *)malloc(sizeof(char)*16);
    
    strcpy(s1, "Erster Speicher"); 
    strcpy(s2, "Zweiter Speicher"); 
    strcpy(s3, "Dritter Speicher"); 

    printf("s1 %s %p\n", s1,s1);
    printf("s2 %s %p\n", s2,s2);
    printf("s3 %s %p\n", s3,s3);

    s2= (char *)realloc(s2, sizeof(char)*16);

    printf("s1 %s %p\n", s1,s1);
    printf("s2 %s %p\n", s2,s2);
    printf("s3 %s %p\n", s3,s3);  

    free(s1);
    free(s2);
    free(s3);

    return 0;
}
