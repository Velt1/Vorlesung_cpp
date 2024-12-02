#include <iostream>
#include "crational.hpp"
using namespace std;
int main()
{
    crational a(1, 2);
    crational b(3, 4);
    crational c(15, 105);
    crational d(0.75);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    return 0;
}