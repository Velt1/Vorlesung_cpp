#include <iostream>
using namespace std;

void CallByValue(int a, int b)
{
        a = a + 10;
        b = b + 20;
}

void CallByPointer(int *a, int *b)
{
        (*a) = (*a) + 10;
        (*b) = (*b) + 20;
}

void CallByReference(int &a, int &b)
{
        a = a + 10;
        b = b + 20;
}

int main()
{
        int a = 5, b = 6, c = 7, d = 8, e = 9, f = 10;
        CallByValue(a, b);
        CallByPointer(&c, &d);
        CallByReference(e, f);

        cout << "a: " << a << endl
             << "b: " << b << endl
             << endl;
        cout << "c: " << c << endl
             << "d: " << d << endl
             << endl;
        cout << "e: " << e << endl
             << "f: " << f << endl
             << endl;

        return 0;
}