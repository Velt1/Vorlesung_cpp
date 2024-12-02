#include <iostream>
using namespace std;

class top
{
public:
        int version;
};

class fahrzeug : top
{
private:
        int leistung;

public:
        fahrzeug() {};
        fahrzeug(int l) { this->setLeistung(l); }
        void setLeistung(int l) { this->leistung = l; }
        friend ostream &operator<<(ostream &o, const fahrzeug &f) { return (o << "Leistung: " << f.leistung); }
};

class reifen : top
{
private:
        double druck = 0.0;

public:
        reifen() {};
        reifen(double d) { this->setDruck(d); }
        void setDruck(double d) { this->druck = d; }
        friend ostream &operator<<(ostream &o, const reifen &r) { return (o << "Druck: " << r.druck); }
};

class pkw : public reifen, public fahrzeug
{
private:
        int alter = 0;

public:
        pkw() {};
        pkw(int a) { this->setAlter(a); }
        pkw(int a, double d) : reifen(d) { this->setAlter(a); }
        pkw(int a, double d, int l) : reifen(d), fahrzeug(l) { this->setAlter(a); }
        void setAlter(int a) { this->alter = a; }
        friend ostream &operator<<(ostream &o, const pkw &p)
        {
                return (o << (fahrzeug)p << " " << (reifen)p << " " << "Alter: " << p.alter);
        }
};

int main()
{
        pkw p1();
        cout << p1 << endl;
        pkw p2(5);
        cout << p2 << endl;
        pkw p3(5, 2.5, 4);
        cout << p3 << endl;
}