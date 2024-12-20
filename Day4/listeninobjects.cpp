#include <iostream>
#include <string>
using namespace std;

struct element
{
        string inhalt;
        int alter;
        element *next;
        element *prev;
};

class liste
{
private:
        element *erstesElement;
        element *letztesElement;

public:
        liste()
        {
                erstesElement = NULL;
                letztesElement = NULL;
        }
        void AddElement(string inhalt, int alter)
        {
                element *neuesElement = new element;
                neuesElement->inhalt = inhalt;
                neuesElement->alter = alter;
                neuesElement->prev = NULL;
                neuesElement->next = NULL;

                if (this->erstesElement == NULL)
                {
                        this->erstesElement = neuesElement;
                }
                else
                {
                        this->letztesElement->next = neuesElement;
                        neuesElement->prev = letztesElement;
                }
                this->letztesElement = neuesElement;
        }
        void OutElemente()
        {
                element *tempOutElement = this->erstesElement;
                int counter = 0;
                while (tempOutElement != NULL)
                {
                        counter++;
                        cout << counter << " Alter ist " << tempOutElement->alter << " Inhalt ist " << tempOutElement->inhalt << endl;
                        tempOutElement = tempOutElement->next;
                }
        }
        void CleanUp()
        {
                element *loeschElement = this->erstesElement;
                element *naechstesElement = NULL;
                int counter = 0;
                while (loeschElement != NULL)
                {
                        naechstesElement = loeschElement->next;
                        counter++;
                        cout << "Loesche Element " << counter << endl;
                        delete loeschElement;
                        loeschElement = naechstesElement;
                }
                this->erstesElement = NULL;
                this->letztesElement = NULL;
        }
        ~liste() { CleanUp(); }

        void SwapElement(element *e)
        {
                element *tempElement = e->next; // setze tempElement zu Element nach e
                if (tempElement == NULL)
                        return;

                e->next = tempElement->next; // Setze next (davor) zu next (danach)
                if (tempElement->next != NULL)
                {
                        tempElement->next->prev = e; // Setze prev (danach danach) zu prev (danach)
                }
                tempElement->prev = e->prev; // setze prev (danach) zu prev (davor)
                if (e->prev != NULL)
                {
                        e->prev->next = tempElement; // setze next (davor davor) zu next ( danach)
                }
                else
                {
                        this->erstesElement = tempElement;
                }
                tempElement->next = e; // next (danach) zu next (davor)
                e->prev = tempElement; // prev (davor) zu prev (danach)

                if (e->next == NULL)
                {
                        this->letztesElement = e;
                }
        }

        void SortAlter()
        {
                element *sortElement = this->erstesElement;
                element *naechstesElement = NULL;
                int counter = 0;
                bool swapped;
                do
                {
                        swapped = false;
                        element *sortElement = this->erstesElement;

                        while (sortElement != NULL && sortElement->next != NULL)
                        {
                                if (sortElement->alter > sortElement->next->alter)
                                {
                                        counter++;
                                        this->SwapElement(sortElement);
                                        swapped = true;
                                }
                                else
                                {
                                        sortElement = sortElement->next;
                                }
                        }
                } while (swapped); // Wiederholen bis alle sotiert sind. (Kein Swap mehr nötig war)

                cout << "Anzahl der Durchläufe: " << counter << endl;
                OutElemente();
        }
};

int main()
{
        liste *l1 = new liste;
        l1->AddElement("Erstes Element", 34);
        l1->AddElement("Zweites Element", 24);
        l1->AddElement("Drittes Element", 67);
        l1->AddElement("Viertes Element", 18);
        l1->AddElement("Fünftes Element", 48);
        l1->AddElement("Sechstes Element", 13);
        l1->AddElement("Siebtes Element", 88);
        l1->OutElemente();
        l1->SortAlter();
        delete l1;
}
