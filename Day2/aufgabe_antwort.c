#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct line {
    char *nachname;
    char *vorname;
    char *strasse;
    char *alter;
};

struct line * GetLine(char *s) 
{
    if (s==NULL || strlen(s)==0) return NULL;

    struct line *newLine = (struct line*)malloc(sizeof(struct line));
    char * nachname = strtok(s,";");
    char * vorname = strtok(NULL, ";");
    char * strasse = strtok(NULL, ";");
    char * alter = strtok(NULL, "\n");

    if (nachname!=NULL){newLine ->nachname = (char *)malloc(sizeof(char)*(strlen(nachname)+1)); strcpy(newLine->nachname,nachname);}
    if (vorname!=NULL){newLine ->vorname = (char *)malloc(sizeof(char)*(strlen(vorname)+1)); strcpy(newLine->vorname,vorname);}
    if (strasse!=NULL){newLine ->strasse = (char *)malloc(sizeof(char)*(strlen(strasse)+1)); strcpy(newLine->strasse,strasse);}
    if (alter!=NULL){newLine ->alter = (char *)malloc(sizeof(char)*(strlen(alter)+1)); strcpy(newLine->alter,alter);}
    return newLine;
};
void PrintLine(int nr, struct line * l)
{
    printf("%3d %-20s %-20s %-20s %5s\n", nr,l->nachname,l->vorname,l->strasse,l->alter);
}
void FreeLine(struct line *l)
{
    if (l!=NULL)
    {
        if(l->nachname != NULL) free(l->nachname);
        if(l->vorname != NULL) free(l->vorname);
        if(l->strasse != NULL) free(l->strasse);
        if(l->alter != NULL) free(l->alter);
        free(l);
    }
}
int main(void)
{
    int lnr=0;
    FILE *fd = NULL;
    fd = fopen("data.txt", "r");
    char buffer[1024];
    while (fgets(buffer,1023,fd)!=NULL) 
    {
        struct line *l= GetLine(buffer);
        PrintLine(++lnr,l);
        FreeLine(l);
    }
    fclose(fd);
    return 0;
}
