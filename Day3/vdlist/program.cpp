#include "vlist.hpp"
#include <iostream>

int main() {
	vlist *l1 = new vlist;
	l1->AddElement("Hans", "Mustermann", 22);
	l1->AddElement("Peter", "Hans", 42);
	l1->AddElement("Olaf", "Schroeder", 33);
	l1->AddElement("Angela", "Merkel", 76);

	l1->Output();
	delete l1;
	return 0;
}
