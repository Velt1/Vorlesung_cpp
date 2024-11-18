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
                        cout << counter << "Alter ist " << tempOutElement->alter << " Inhalt ist " << tempOutElement->inhalt << endl;
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
                        cout << "Loesche Element " << counter << endl;
                        delete loeschElement;
                        loeschElement = naechstesElement;
                }
                this->erstesElement = NULL;
                this->letztesElement = NULL;
        }
        ~liste() { CleanUp(); }
};

int main()
{
        liste *l1 = new liste;
        l1->AddElement("Erstes Element", 34);
        l1->AddElement("Zweites Element", 24);
        l1->AddElement("Drittes Element", 67);
        l1->AddElement("Viertes Element", 18);
        l1->OutElemente();
        delete l1;
}
