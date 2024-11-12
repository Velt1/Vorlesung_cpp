#include<iostream>

using namespace std;
int main()
{
    for (int i=0, e=1 ; i < 10; i++, e+=2) 
    {
        cout << "i:" << i << ", e:" << e << endl;     
    }
    return 0;
}
