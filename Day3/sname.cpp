#include<iostream>
#include<string.h>
using namespace std;

struct sname
{
    char *nachname;
    char *vorname;
};

int main() 
{
    sname *name1 = NULL;

    // Speicher für Srcuts selbst reservieren
    name1 = new sname;

    // Speicher für Inhalt
    name1->nachname = new char[32];
    name1->vorname = new char[32];

    // Speicher beschreiben
    strcpy(name1->nachname, "Mustermann");
    strcpy(name1->vorname,"Gabriele");

    // Ausgabe
    cout << "Vorname " << name1->vorname << ", Nachname " << name1->nachname << endl;
    delete [] name1->vorname;
    delete [] name1->nachname;

    delete name1;

    return 0;
}
