#include <iostream>
#include <string>
using namespace std;

struct element
{
        string inhalt;
        element *next;
        element *prev;
};

int main()
{
        element *liste = NULL;
        element *erstesElement = NULL;
        element *letztesElement = NULL;

        // erstes Element in die Liste - Alternative
        // liste = new element;
        // liste->inhalt = "Erstes Element";
        // liste->next = NULL;
        // liste->prev = NULL;

        // erstes Element in die Liste
        // erstellt neues Element auf dem Heap, Die Adresse wird dem zeiger element1 zugewiesen.
        //*element1 weiß jetzt wo element1 liegt.
        element *element1 = new element; // Es wird nur hier etwas erstellt, der Rest ist Zeiger verschieben
        // -> wird nur bei Zeigern verwendet
        element1->inhalt = "Erstes Element";
        element1->next = NULL;
        element1->prev = NULL;

        liste = element1;
        erstesElement = element1;
        letztesElement = element1;

        /* zweites Element */
        element *element2 = new element;
        element2->inhalt = "Zweites Element";
        element2->next = NULL;
        element2->prev = NULL;
        letztesElement->next = element2;
        element2->prev = letztesElement;
        letztesElement = element2;

        // drittes Element
        element *element3 = new element;
        element3->inhalt = "Drittes Element";
        element3->next = NULL;
        element3->prev = NULL;
        letztesElement->next = element3;
        element3->prev = letztesElement;
        letztesElement = element3;

        // Ausgabe!
        element *OutputTempElement = erstesElement;

        while (OutputTempElement != NULL)
        {
                cout << OutputTempElement->inhalt << endl;
                OutputTempElement = OutputTempElement->next;
        }

        // Speicher freigeben
        element *loeschElement = erstesElement;
        element *naechstesElement = NULL;

        while (loeschElement != NULL)
        {
                cout << "Loesche Element " << endl;
                naechstesElement = loeschElement->next; // das nächste Element zwischenspeichern als Zeiger
                delete loeschElement;                   // das Element löschen
                loeschElement = naechstesElement;       // Zeiger auf das nächste Element
        }

        return 0;
}