#include "vlist.hpp"

//Destruktor (wird bei delete aufgerufen)

vlist::~vlist()
{
	if(this -> elemente == NULL) return;

	namen * tempElement = GetFirstElement();
	for(namen * nextElement = tempElement -> next;tempElement != NULL; tempElement = nextElement)
	{
		nextElement = tempElement -> next;
		delete tempElement;
	}
	this -> elemente = NULL;
}

namen * vlist::GetFirstElement()
{
 	if(this -> elemente == NULL) return NULL;

	while (this -> elemente -> prev != NULL) this -> elemente = this -> elemente -> prev;
	return this -> elemente;
}

namen * vlist::GetLastElement()
{
	if(this -> elemente == NULL) return NULL;

	while (this -> elemente -> next != NULL) this -> elemente = this -> elemente -> next;
	return this -> elemente;

}

void vlist::AddElement(std::string vorname, std::string nachname, int a)
{
	namen *newElement = new namen(vorname, nachname,a);
	if(this -> elemente == NULL)
		this -> elemente = newElement;
	else
	{
		namen * lastElement = this -> GetLastElement();
		lastElement -> next = newElement;
		newElement -> prev = lastElement;
	}
}


void vlist::AddElement(namen n)
{
	this -> AddElement(n.vorname, n.nachname, n.alter);
}

void vlist::InsertElement(std::string vorname, std::string nachname, int a)
{
	if (this -> elemente == NULL) this -> AddElement(vorname,nachname,a);
	else
	{
		namen * newElement = new namen(vorname, nachname,a);
		namen * firstElement = GetFirstElement();
		newElement -> prev = firstElement;
		firstElement -> prev = newElement;	
	}
}

void vlist::InsertElement(namen n)
{
	this -> InsertElement(n.vorname, n.nachname, n.alter);
}

void vlist::Output()
{
	if(this -> elemente == NULL) return;
	namen * tempElement = GetFirstElement();
	for(; tempElement != NULL; tempElement = tempElement -> next) tempElement -> Output();	
}
