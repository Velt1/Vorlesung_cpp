#include "vlist.hpp"
#include <iostream>
vlist::~vlist() {
	if (this->elemente == NULL) return;

	namen *tempElement = GetFirstElement();
	for (namen *nextElement = NULL; tempElement != NULL;
	     tempElement = nextElement) {
		nextElement = tempElement->next;
		delete tempElement;
	}
}

namen *vlist::GetFirstElement() {
	if (this->elemente == NULL) return NULL;

	while (this->elemente->prev != NULL)
		this->elemente = this->elemente->prev;
	return this->elemente;
}
namen *vlist::GetLastElement() {
	if (this->elemente == NULL) return NULL;

	while (this->elemente->next != NULL)
		this->elemente = this->elemente->next;
	return this->elemente;
}

void vlist::AddElement(std::string vorname, std::string nachname, int a) {
	if (this->elemente == NULL) {
		throw std::runtime_error(
		    "Error: Attempt to add an element to an uninitialized list "
		    "(elemente is NULL).");
	}
	namen *lastElement = this->GetLastElement();
	namen *newElement = new namen(vorname, nachname, a);
	lastElement->next = newElement;
	newElement->prev = lastElement;
}

void vlist::AddElement(namen n) {
	this->AddElement(n.vorname, n.nachname, n.alter);
}

void vlist::InsertElement(std::string vorname, std::string nachname, int a) {
	if (this->elemente == NULL)
		this->AddElement(nachname, vorname, a);
	else {
		namen *newElement = new namen(vorname, nachname, a);
		namen *firstElement = GetFirstElement();
		newElement->next = firstElement;
		firstElement->prev = newElement;
	}
}
void vlist::InsertElement(namen n) {
	this->InsertElement(n.vorname, n.nachname, n.alter);
}
void vlist::Output() {
	if (this->elemente == NULL) return;
	namen *tempElement = GetLastElement();
	while (tempElement != NULL)
		tempElement->Output();
}
