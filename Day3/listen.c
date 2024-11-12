#include<stdlib.h>
#include<stdio.h>

struct vlisttest
{
    int alter;
    int plz;
    struct vlisttest *nextElement;
};

/* global firstElement */
struct vlisttest *firstElement = NULL;
/* Solange firstElement == NULL, solange ist die Liste leer */

struct vlisttest *NewElement (int a, int p)
{
    struct vlisttest *newElement = (struct vlisttest*)malloc(sizeof(struct vlisttest));
    newElement->alter = a;
    newElement->plz = p;
    newElement->nextElement = NULL;
    return newElement;
}

void AddElement(int a, int p)
{
    struct vlisttest *newElement = NewElement(a,p);
    if (firstElement == NULL) firstElement = newElement;
    else
    {
        struct vlisttest *tempElement = firstElement;
        while (tempElement->nextElement != NULL) tempElement = tempElement->nextElement;
        tempElement->nextElement = newElement;
    }

}
void InsertElement(int a, int p)
{
    struct vlisttest *newElement = NewElement(a,p);
    newElement->nextElement = firstElement;
    firstElement = newElement;
}
void PrintVlist()
{
    struct vlisttest * tempElement = firstElement;
    for(;tempElement != NULL; tempElement=tempElement->nextElement) printf("%4d %05d\n", tempElement->alter,tempElement->plz);
}

void FreeVlist()
{
    struct vlisttest *tempElement = firstElement;
    for(;tempElement != NULL; tempElement=firstElement )
    {
        firstElement = tempElement->nextElement;
        free(tempElement);
    }
}

int main(void)
{
    AddElement(44,4275);
    AddElement(34,4233);
    AddElement(12,3443);
    InsertElement(55,10444);
    PrintVlist();
    FreeVlist();
}
