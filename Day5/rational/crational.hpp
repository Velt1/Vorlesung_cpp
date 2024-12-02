#include <iostream>
using namespace std;

#ifndef CRATIONAL_HPP
#define CRATIONAL_HPP

class crational
{
private:
    int zaehler = 0;
    int nenner = 1;
    void Kuerze();
    void SetRational(int, int);
    int GetGGt(int, int);

public:
    crational();
    crational(int);
    crational(int, int);
    crational(const crational &);
    crational(double);
    ~crational() { cout << "~crational()" << endl; }
    friend ostream &operator<<(ostream &os, crational &c);
    // Operatoren
    crational &operator=(const crational &);
    crational operator+(const crational &);
    crational operator-(const crational &);
    crational operator/(const crational &);
    crational operator*(const crational &);
    crational operator++();
    crational operator++(int);
    bool operator==(const crational &);
    bool operator!=(const crational &);
    bool operator<(const crational &);
    bool operator<=(const crational &);
    bool operator>(const crational &);
    bool operator>=(const crational &);
};

#endif