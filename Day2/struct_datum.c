#include<stdlib.h>
#include<stdio.h>
struct datum 
{
    int tag;
    int monat;
    int jahr;
};

int main(void)
{
    struct datum d1;
    d1.tag = 4;
    d1.monat = 11;
    d1.jahr = 2024;

    printf("%02d.%02d.%d\n", d1.tag,d1.monat,d1.jahr);
    /* Anfang des neuen Kapitels */
    struct datum *pd1 = NULL;
    pd1->tag = 4;
    (*pd1).monat = 11;
    pd1->jahr = 2024;
    printf("Date PTR: %02d,%02d.%d\n",pd1->tag,pd1->monat,(*pd1).jahr);

    free(pd1);

    /* Mehrere Elemente */
    struct datum *pd2 = (struct datum *)malloc(sizeof(struct datum)*3);
    pd2[0].tag = 1;
    pd2[0].monat = 2;
    pd2[0].jahr = 2001;

    pd2[1].tag = 3;
    pd2[1].monat = 10;
    pd2[1].jahr = 2022;

    pd2[2].tag = 4;
    pd2[2].monat = 11;
    pd2[2].jahr = 2024;

    printf("Date PTR: %02d,%02d.%d\n",pd2[0].tag,pd2[0].monat,pd2[0].jahr);
    printf("Date PTR: %02d,%02d.%d\n",pd2[1].tag,pd2[1].monat,pd2[1].jahr);
    printf("Date PTR: %02d,%02d.%d\n",pd2[2].tag,pd2[2].monat,pd2[2].jahr);

    free(pd2);

    return 0;
}
