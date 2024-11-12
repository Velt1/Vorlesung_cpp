#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char *c1 = NULL;
    char *c2 = NULL;

    c1 = new char;
    c2 = new char[1024]; // Reservieren mit []

    *c1 = 'r';
    strcpy(c2,"Mustermann");

    cout << "c1: " << c1 << ", und c2: " << c2 << endl;

    delete c1;
    delete [] c2; // Freigeben auch mit []
}
