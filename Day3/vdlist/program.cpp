#include<iostream>
#include "vlist.hpp"

int main()
{
	vlist *l1 = new vlist;

	l1 -> AddElement("Hans", "Zimmer", 50);
	l1 -> AddElement("Hilde","Garde", 70);
	l1 -> AddElement("Angelo", "Merte", 58);
	l1 -> AddElement("Daniel", "Jung", 46);

	l1 -> Output(),

	delete l1;
	return 0;

}

