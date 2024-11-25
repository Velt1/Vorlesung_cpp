#include <iostream>
using namespace std;

class mystring
{
private:
        char *data;
        bool isinit = false;
        int length = 0;
        int StringLen(const char *str)
        {
                int i = 0;
                while (str[i] != '\0')
                        i++;
                return i;
        }
        void SetData(const char *data)
        {
                if (this->isinit)
                        delete[] this->data;
                isinit = true;
                int strlen = StringLen(data);
                this->data = new char[strlen + 1];
                for (int i = 0; i <= strlen; i++)
                        this->data[i] = data[i];
                this->length = this->StringLen(this->data);
        }

public:
        mystring() { data = NULL; } // Standardkonstruktor
        mystring(const char *data)  // Wertekonstruktor
        {
                cout << "mystring(const char * " << data << ")" << endl;
                this->SetData(data);
        }
        mystring(const mystring &m)
        {
                cout << "mystring(const mystring &" << m.data << ")" << endl;
                this->SetData(m.data);
        }
        ~mystring() // Destruktor
        {
                cout << "~mystring()" << endl;
                if (this->isinit)
                        delete[] this->data;
                this->data = NULL;
        }

        void Output()
        {
                cout << this->data;
        }
        // Operator: Die Zuweisung eines Objekts an ein anderes Objekt
        mystring &operator=(const mystring &m)
        {
                cout << "Operator = (" << m.data << ")" << endl;
                this->SetData(m.data);
                return *this;
        }
        mystring operator+(const mystring &m)
        {
                cout << "Operator + (" << m.data << ")" << endl;
                int len1 = this->StringLen(this->data);
                int len2 = this->StringLen(m.data);
                char *newData = new char[len1 + len2 + 1];
                for (int i = 0; i < len1; i++)
                        newData[i] = this->data[i];
                for (int i = 0; i < len2; i++)
                        newData[len1 + i] = m.data[i];
                newData[len1 + len2] = '\0';
                mystring newString(newData);
                delete[] newData;
                return newString;
        }
        friend ostream &operator<<(ostream &os, const mystring &m);
};

int mystring::StringLen(const char *str)
{
        int i = 0;
        while (str[i] != '\0')
                i++;
        return i;
}
std::ostream &operator<<(std::ostream &os, const mystring &m)
{
        os << m.data;
        return os;
}

int main()
{
        mystring a("TestString");
        mystring b("Zwei");
        mystring c("");
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;
        cout << "--------------------" << endl;
        c = a + b + "Drei";
        cout << "--------------------" << endl;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;
        return 0;
}