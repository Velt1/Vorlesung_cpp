#include <iostream>
#include <string>

using namespace std;

struct name {
  string vorname;
  string nachname;
  name *next;
};

name *NewElement(string nachname, string vorname) {
  name *newElement = new name;
  newElement->nachname = nachname;
  newElement->vorname = vorname;
  newElement->next = NULL;
  return newElement;
}

name *InsertElement(name *firstElement, string nachname, string vorname) {
  name *newElement = NewElement(nachname, vorname);
  newElement->next = firstElement;
  return newElement;
}

void PrintVlist(name *firstElement) {
  for (; firstElement != NULL; firstElement = firstElement->next)
    cout << "N: " << firstElement->nachname << ", V: " << firstElement->vorname
         << endl;
}

name *RevertVlist(name *firstElement) {
  name *newFirstElement = NULL;

  while (1) {
    name *tempElement = firstElement;
    if (tempElement->next == NULL) {
      // letztes Element anhängen
    }
    while (tempElement->next->next != NULL)
      tempElement = tempElement->next;
    // jetzt sind wir im vorletzten Element
    // letztes Element anhängen
    if (newFirstElement == NULL) {
      newFirstElement = tempElement->next;
      tempElement->next = NULL;
    } else {
      name *newTempElement = newFirstElement;
      while (newTempElement->next != NULL)
        newTempElement = newTempElement->next;
      newTempElement->next = tempElement->next;
      tempElement->next = NULL;
    }
  }
}

name *FreeList(name *firstElement) {
  name *tempElement = firstElement;
  for (; firstElement != NULL; tempElement = firstElement) {
    firstElement = tempElement->next;
    delete tempElement;
  }
  return NULL;
}

int main() {
  name *l1 = NULL;
  l1 = InsertElement(l1, "Mustermann", "Hans");
  l1 = InsertElement(l1, "Lorald", "Sabine");
  l1 = InsertElement(l1, "Fritsche", "Jack");
  PrintVlist(l1);
  l1 = RevertVlist(l1);
  PrintVlist(l1);
  FreeList(l1);
  return 0;
}
