#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    int mtrnr;
    char *nachname;
    char *vorname;
};

void printstudent(struct student *s)
{
    printf("%d, %s, %s\n", s->mtrnr, s->nachname, s->vorname);
}

int main(void)
{
    struct student s1;
    s1.mtrnr = 1000;
    s1.nachname = (char*)malloc(sizeof(char)*32);
    s1.vorname = (char*)malloc(sizeof(char)*32);
    strcpy(s1.nachname,"Mustermann");
    strcpy(s1.vorname,"Hans");
    printstudent(&s1);
    free(s1.nachname);
    free(s1.vorname);

    struct student *ps1 = NULL;
    ps1 = (struct student*)malloc(sizeof(struct student));
    ps1->mtrnr = 1001;
    ps1->nachname = (char*)malloc(sizeof(char)*32);
    ps1->vorname = (char*)malloc(sizeof(char)*32);
    strcpy(ps1->nachname,"Mann");
    strcpy(ps1->vorname,"Meyer");
    printstudent(ps1);
    free(ps1->nachname);
    free(ps1->vorname);
    free(ps1);

    return 0;
}
