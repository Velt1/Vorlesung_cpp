#include<iostream>

using namespace std;
struct alter
{
    int alter;
    int plz;
};

int main()
{
    alter a;
    a.alter = 55;
    a.plz = 04425;

    cout << a.alter << ":" << a.plz << endl;

    //dynamisch
    alter *pa = NULL;
    pa = new alter;
    pa->alter=33;
    pa->plz = 17222;

    cout << pa->alter << ":" << pa->plz << endl;
    return 0;

}
