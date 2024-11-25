#include <iostream>
#include <string>

using namespace std;
class fahrzeug
{
private:
        string name;
        int version;

protected:
public:
        fahrzeug() { this->version = 1; }
        fahrzeug(int v) { this->version = v; }
        fahrzeug(int v, string n)
        {
                this->version = v;
                this->name = n;
        }
        void setName(string n) { this->name = n; }
        string getName() { return this->name; }
};

int main()
{
        // Statisches Reservieren
        fahrzeug f1;
        f1.setName("Blaues Auto");

        cout << f1.getName() << endl;

        fahrzeug f2(3);
        f2.setName("Gelbes Vroom Vroom");

        fahrzeug f3(3, "schwarzes Auto");

        fahrzeug *f4 = new fahrzeug();
        f4->setName("Gruenes Fahrzeug");
        cout << f4->getName() << endl;

        fahrzeug *f5 = new fahrzeug(66, "Helles Auto");
        cout << f5->getName() << endl;
        delete f4;
        delete f5;
}