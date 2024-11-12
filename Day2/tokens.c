#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    char *s1 = (char*)malloc(sizeof(char)*1024);
    strcpy(s1,"mustermann:Mustermann:Hans:Musterstr.:15");

    char *username = NULL;
    char *lastname = NULL;
    char *firstname = NULL;
    char *street = NULL;
    char *streetnr = NULL;

    username = strtok(s1, ":");
    lastname = strtok(NULL, ":");
    firstname = strtok(NULL, ":");
    street = strtok(NULL, ":");
    streetnr = strtok(NULL, ":");

    printf("username:  %s\n", username);
    printf("lastname:  %s\n", lastname);
    printf("firstname:  %s\n", firstname);
    printf("street:  %s\n", street);
    printf("streetnr:  %s\n", streetnr);

    free(s1);
    return 0;
}
