#include "crational.hpp"
using namespace std;

#ifndef CRATIONAL_CPP
#define CRATIONAL_CPP

crational::crational() {}

crational::crational(int z)
{
        cout << "crational(int)" << endl;
        this->SetRational(z, 1);
}

crational::crational(int z, int n)
{
        cout << "crational(int, int)" << endl;
        this->SetRational(z, n);
}

crational::crational(const crational &c)
{
        cout << "crational(crational &)" << endl;
        this->SetRational(c.zaehler, c.nenner);
}

crational::crational(double d)
{
        cout << "crational(double)" << endl;
        int n = 1;
        while (d - (int)d != 0.0)
        {
                d = d * 10;
                n = n * 10;
        }
        this->SetRational((int)d, n);
}

void crational::Kuerze()
{
        // GGT euklidischer Algorithmus
        int ggt = GetGGt(this->zaehler, this->nenner);
        this->zaehler /= ggt;
        this->nenner /= ggt;
        if (this->nenner < 0)
        {
                this->zaehler = -this->zaehler;
                this->nenner = -this->nenner;
        }
}

int crational::GetGGt(int a, int b)
{
        if (b == 0)
                return a;
        else
                return GetGGt(b, a % b);
}

void crational::SetRational(int z, int n)
{
        this->zaehler = z;
        this->nenner = n;
        this->Kuerze();
}

ostream &operator<<(ostream &os, crational &c)
{
        os << "Z: " << c.zaehler << "/N:" << c.nenner;
        return os;
}

crational &crational::operator=(const crational &c)
{
        this->SetRational(c.zaehler, c.nenner);
        return *this;
}

crational crational::operator+(const crational &c)
{
        int z = this->zaehler * c.nenner + this->nenner * c.zaehler;
        int n = this->nenner * c.nenner;
        crational temp(z, n);
        return temp; // Überblendung bedeudet temporäres Objekt erstellen!!!!!
}

crational crational::operator-(const crational &c)
{
        int z = this->zaehler * c.nenner - this->nenner * c.zaehler;
        int n = this->nenner * c.nenner;
        crational temp(z, n);
        return temp;
}

crational crational::operator/(const crational &c)
{
        int z = this->zaehler / c.zaehler;
        int n = this->nenner / c.nenner;
        crational temp(z, n);
        return temp;
}

crational crational::operator*(const crational &c)
{
        int z = this->zaehler * c.zaehler;
        int n = this->nenner * c.nenner;
        crational temp(z, n);
        return temp;
}
crational &crational::operator++()
{
        cout << "operator++()" << endl;
        *this = this->operator+(crational(1, 1));
        return *this;
}

crational &crational::operator++(int i)
{
        cout << "operator++(int)" << endl;
        *this = this->operator+(crational(1, 1));
        return *this;
}

bool crational::operator==(const crational &c)
{
        return this->zaehler == c.zaehler && this->nenner == c.nenner;
}

bool crational::operator!=(const crational &c)
{
        return this->zaehler != c.zaehler || this->nenner != c.nenner;
}

bool crational::operator>(const crational &c)
{
        return this->zaehler * c.nenner > this->nenner * c.zaehler;
}

bool crational::operator>=(const crational &c)
{
        return this->zaehler * c.nenner >= this->nenner * c.zaehler;
}

bool crational::operator<(const crational &c)
{
        return this->zaehler * c.nenner < this->nenner * c.zaehler;
}

bool crational::operator<=(const crational &c)
{
        return this->zaehler * c.nenner <= this->nenner * c.zaehler;
}

#endif