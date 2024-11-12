#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int counter = 1;
struct student 
{
    char *vorname;
    char *nachname;
    char *street;
    char *age;
};

void printstudent(struct student *s)
{
    printf("%d, %s, %s, %s, %s\n",counter, s->vorname, s->nachname, s->street,s->age);
    counter++;
}

void free_student(struct student *s) {
    free(s->vorname);
    free(s->nachname);
    free(s->street);
}

struct student allocate_struct(struct student r)
{
    r.vorname = (char*)malloc(sizeof(char)*32);
    r.nachname = (char*)malloc(sizeof(char)*32);
    r.street = (char*)malloc(sizeof(char)*32);
    r.age = (char*)malloc(sizeof(char)*32);
    return r;
}
int main(void)
{
    char *s1 = (char*)malloc(sizeof(char)*1024);
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file\n");
        free(s1);
        return 1;
    }

    if (fgets(s1, 1024, file) == NULL) {
        fprintf(stderr, "Error reading file\n");
        fclose(file);
        free(s1);
        return 1;
    }

    // Datei schließen
    fclose(file);

    // Ausgabe des Inhalts
    printf("Inhalt von s1: %s\n", s1);

    
    strcpy(s1,"Hans:Mustermann:Musterstr.15:22");
    struct student r1;
    r1 = allocate_struct(r1);
    r1.vorname = strtok(s1, ":");
    r1.nachname = strtok(NULL, ":");
    r1.street = strtok(NULL, ":");
    r1.age = strtok(NULL, ":");
    printstudent(&r1);
    free(s1);
    return 0;
}
