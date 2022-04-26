#include <iostream>
#include "Common.h"
#include "ListA.h"

using namespace std;

ListA* newAList() {
	ListA* list = new ListA;
	list->tabSize = 5;
	list->tab = new int[list->tabSize];
	list->counter = 0;
	return list;
}

void destroyAList(ListA* list) {
	if (list != nullptr) {
		delete[] list->tab;
		delete list;
	}
}

void resize(ListA* list) {
	list->tabSize = list->tabSize * 2;
	int *tab1 = new int[list->tabSize];
	for (int i = 0; i < list->tabSize; i++)
	{
		tab1[i] = list->tab[i];
		if (list->tab[i+1] == NULL)
		{
			break;
		}
	}
	delete[] list->tab;
	list->tab = tab1;
}

void addToAList(ListA* list, int value) {
	if (list->counter == list->tabSize)
	{
		resize(list);
	}
	list->tab[list->counter] = value;
	list->counter++;
}

int getFromAList(ListA* list, int index) {
	if (index >= list->counter || index < 0)
	{
		return NaN;
	}
	return list->tab[index];
}

int removeFromAList(ListA* list, int index) {
	if (index >= list->counter)
	{
		return 0;
	}
	int wynik = list->tab[index];
	int j = index + 1;
	while (j < list->counter)
	{
		list->tab[j - 1] = list->tab[j];
		j++;
	}
	list->counter = list->counter - 1;
	return wynik;
}

int sizeA(ListA* list) {
	return list->counter;
}

auto_ptr<IteratorA> getAIterator(ListA* list) {
	IteratorA* nowy = new IteratorA;
	nowy->list = list;
	nowy->counter = 0;
	return auto_ptr<IteratorA>(nowy);
}

int iterateA(IteratorA* iterator) {
	ListA* nowy = iterator->list;
	int index = iterator->counter;
	int wynik;
	if (index >= nowy->counter)
	{
		 wynik = NaN;
	}
	else
	{
		wynik = nowy->tab[index];
	}
	iterator->counter++;
	return wynik;
}
