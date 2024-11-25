#include <iostream>
#include <string>

using namespace std;

class fahrzeug
{
private:
    int version;

protected:
    int countAxes;

public:
    fahrzeug()
    {
        cout << "Fahrzeug()" << endl;
        this->version = 1;
    }
    fahrzeug(int v)
    {
        cout << "Fahrzeug (" << v << ")" << endl;
        this->version = v;
    }
    fahrzeug(int v, int c)
    {
        cout << "Fahrzeug (" << v << ", " << c << ")" << endl;
        this->version = v;
        this->setCountAxes(c);
    }
    ~fahrzeug()
    {
        cout << "~Fahrzeug()" << endl;
    }
    int getCountAxes() { return this->countAxes; }
    void setCountAxes(int c) { this->countAxes = c; }
};

class Auto : public fahrzeug
{
private:
    string farbe;

protected:
    string typ;

public:
    Auto() { cout << "Auto()" << endl; }
    Auto(int v, int c, string f) : fahrzeug(v, c)
    {
        cout << "Auto (" << v << ", " << c << ", " << f << ")" << endl;
        this->setFarbe(f);
    }
    void setFarbe(string f) { this->farbe = f; }
    string getFarbe() { return this->farbe; }
};

int main()
{
    cout << "Farzeug f1" << endl;
    fahrzeug f1(1, 2);
    Auto a1;
    a1.setFarbe("Blau");
    a1.setCountAxes(4);
    cout << a1.getFarbe() << endl;

    cout << "Ein weiteres Auto erzeugen" << endl;
    Auto a2(10, 2, "Schwarz");

    // a1 = f1; // Fehler, weil f1 nicht alles von a1 hat!!
    f1 = a2; // Ok
}