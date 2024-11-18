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

        element *SwapElement(element *ae)
        {
                if (ae->next == NULL)
                        return ae;
                if (ae->prev == NULL && ae->next)
                        return ae;
                element *pe = ae->prev;
                element *ne = ae->next;
                element *nne = ne->next;

                if (pe != NULL && nne != NULL)
                {
                        pe->next = ne;
                        ne->prev = pe;
                }
        }

        void SortAlter()
        {
                element *sortElement = this->erstesElement;

                while (sortElement->next != NULL)
                {
                        if (sortElement->alter > sortElement->next->alter)
                        {
                                sortElement = this->SwapElement(sortElement);
                                if (sortElement->prev != NULL)
                                {
                                        sortElement = sortElement->prev;
                                        continue;
                                }
                        }
                        sortElement = sortElement->next;
                }
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
