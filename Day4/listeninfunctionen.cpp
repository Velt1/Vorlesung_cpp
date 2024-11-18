#include <iostream>
#include <string>
using namespace std;

struct element
{
        string inhalt;
        element *next;
        element *prev;
};

element *erstesElement = NULL;
element *letztesElement = NULL;

void AddElement(string inhalt)
{
        // erstellt neues Element auf dem Heap, Die Adresse wird dem zeiger neuesElement zugewiesen.
        element *neuesElement = new element;
        neuesElement->inhalt = inhalt;
        neuesElement->prev = NULL;
        neuesElement->next = NULL;

        if (erstesElement == NULL)
        {
                erstesElement = neuesElement;
        }
        else
        {
                // hinten anhängen
                letztesElement->prev = letztesElement;
                letztesElement->next = neuesElement;
        }
        letztesElement = neuesElement; // wird in if uns else ausgeführt
}

void OutElements()
{
        element *outputElement = erstesElement;
        int counter = 0;
        while (outputElement != NULL)
        {
                counter++;
                cout << counter << ": " << outputElement->inhalt << endl;
                outputElement = outputElement->next;
        }
}

void CleanUp()
{
        element *loeschElement = erstesElement;
        element *nextElement = NULL;

        int counter = 0;
        while (loeschElement != NULL)
        {
                counter++;
                cout << "Loesche Element " << counter << endl;
                nextElement = loeschElement->next;
                delete loeschElement;
                loeschElement = nextElement;
        }
}

int main()
{
        AddElement("ErstesElement");
        AddElement("ZweitesElement");
        AddElement("DrittesElement");
        AddElement("ViertesElement");

        OutElements();
        CleanUp();
        return 0;
}