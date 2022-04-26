#include <iostream>
#include "Common.h"
#include "ListP.h"
#include "ListPTest.h"

using namespace std;

Element* newElement(int value);

ListP* newPList() {
	ListP* list = new ListP;
	list->first = NULL;
	list->last = NULL;
	list->rozmiar = 0;
	return list;
}

void destroyPList(ListP* list) {
	if (list != NULL) {
		while (list->first != NULL) {
			Element* curr = list->first;
			if (list->first == list->last) list->first = NULL;
			else list->first = list->first->next;
			delete curr;
		}
		delete list;
	}
}

void addToPList(ListP* list, int value) {
	Element* nowy = newElement(value);
	Element* poprzedni = list->first;
	if (list->first == NULL)
	{
		list->first = nowy;
	}
	if (list->last == NULL)
	{
		list->last = nowy;
	}
	else
	{
		poprzedni = list->last;
		list->last = nowy;
		poprzedni->next = list->last;
	}
}

Element* search(ListP* list, int value) {
	Element* curr = list->first;
	int wartosc;
	while (curr->next != NULL)
	{
		wartosc = curr->value;
		if (wartosc == value)
		{
			return curr;
		}
		curr = curr->next;
	}
	return 0;
}

int getFromPList(ListP* list, int index) {
	Element* curr = list->first;
	for (int i = 0; i < index;i++) {
		curr = curr->next;
	}
	int value;
	if (curr == NULL)
	{
		value = NaN;
	}
	else
	{
		value = curr->value;
	}
	return value;
}

Element* newElement(int value) {
	Element* element = new Element;
	element->value = value;
	element->next = NULL;
	return element;
}

int removeFromPList(ListP* list, int index) {
	Element* curr = list->first;
	int i = 0;
	Element* prev = NULL;
	while (curr != NULL && i < index) {
		prev = curr;
		curr = curr->next;
		i++;
	}
	int value;
	if (curr == NULL) { //Będzie null jeśli lista jest pusta
		list->last = prev;
		value = NaN;
	}
	else { 
		if (prev != NULL) { //Sprawdzant czy to nie pierwszy element listy		
			prev->next = curr->next;			
		}
		else {
			list->first = curr->next;
		}		
		if (curr->next == NULL) { //Jak koniec kolejki
			list->last = prev;
		}
		value = curr->value;
		list->rozmiar--;
		delete curr;
	}
	return value;
}

int sizeP(ListP* list) {
	if (list!=NULL)
		return list->rozmiar;
	return NaN;
}

auto_ptr<IteratorP> getPIterator(ListP* list) {
	IteratorP* nowy = new IteratorP;
	nowy->list = list;
	nowy->curr = list->first;
	return auto_ptr<IteratorP>(nowy);
}

int iterateP(IteratorP* iterator) {
	Element* curr = iterator->curr;
	int wartosc;
	if (curr == nullptr)
	{
		wartosc = NaN;
	}
	else
	{
		wartosc = curr->value;
	}
	if (curr != nullptr)
	{
		iterator->curr = curr->next;
	}
	return wartosc;
}