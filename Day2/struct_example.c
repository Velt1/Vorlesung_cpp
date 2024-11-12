#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
    char nachname[128];
    char vorname[128];
    int alter;
};

int  main(void)
{
    struct student s1;

    strcpy(s1.nachname, "Mustermann");
    strcpy(s1.vorname, "Hans");
    s1.alter = 22;

    printf("Nachname: %s\n", s1.nachname);
    printf("Vorname: %s\n", s1.vorname);
    printf("Alter: %d\n", s1.alter);
}
