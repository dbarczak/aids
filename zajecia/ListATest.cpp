#include <iostream>
#include "Common.h"
#include "ListA.h"
#include "ListATest.h"

using namespace std;

void printAList(ListA* list) {
	if (list->counter == 0) {
		cout << "Lista jest pusta" << endl;
	}
	else {
		for (int i = 0; i < list->counter; i++) {
			cout << list->tab[i] << endl;
		}
	}
}

bool sprawdzPoprawnoscA(ListA* list, int poprawneElementyListy[]) {
	bool blad = 0;
	int curVal;
	for (int i = 0; i < sizeA(list); i++) {
		curVal = getFromAList(list, i);
		if (curVal != poprawneElementyListy[i]) {
			blad = 1;
			break;
		}
	}
	if (blad) {
		cout << "!!! BLAD !!!" << endl;
	}
	else {
		cout << " OK " << endl;
	}
	return blad;
}

void ListATest() {
	cout << "Test lista tablicowa" << endl;
	ListA* myList = newAList();
	printAList(myList);
	addToAList(myList, 0);
	addToAList(myList, 1);
	addToAList(myList, 2);
	addToAList(myList, 3);
	addToAList(myList, 4);
	printAList(myList);
	//Zmienne testowe
	int odczyt;
	bool poprawnosc;
	odczyt = getFromAList(myList, 2);
	poprawnosc = odczyt == 2;
	cout << "Odczytalem=" << odczyt << " Wynik=" << poprawnosc << endl;
	odczyt = getFromAList(myList, 4);
	poprawnosc = odczyt == 4;
	cout << "Odczytalem=" << odczyt << " Wynik=" << poprawnosc << endl;
	odczyt = getFromAList(myList, 5);
	poprawnosc = odczyt == NaN;
	cout << "Odczytalem=" << odczyt << " Wynik=" << poprawnosc << endl;
	//============= TEST USUWANIA ===============	
	int wyn, toRemove, sizePrzed, sizePo;
	toRemove = 2;
	sizePrzed = sizeA(myList);
	wyn = removeFromAList(myList, toRemove);
	sizePo = sizeA(myList);
	cout << "Usuwanie elementu o indeksie: " << toRemove << " Rozmiar zmienił sie poprawnie: " << (sizePo == sizePrzed - 1) << " Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4 };
		sprawdzPoprawnoscA(myList, tab);
	}
	//				
	addToAList(myList, 5);
	cout << "Dodanie elementu 5 na koniec: " << "Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4, 5 };
		sprawdzPoprawnoscA(myList, tab);
	}
	toRemove = 5;
	sizePrzed = sizeA(myList);
	wyn = removeFromAList(myList, toRemove);
	sizePo = sizeA(myList);
	cout << "Usuwanie elementu o indeksie: " << toRemove << "  Rozmiar zmienił sie poprawnie: " << (sizePo == sizePrzed) << " Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4, 5 };
		sprawdzPoprawnoscA(myList, tab);
	}
	toRemove = 4;
	sizePrzed = sizeA(myList);
	wyn = removeFromAList(myList, toRemove);
	sizePo = sizeA(myList);
	cout << "Usuwanie elementu o indeksie: " << toRemove << "  Rozmiar zmienił sie poprawnie: " << (sizePo == sizePrzed - 1) << " Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4 };
		sprawdzPoprawnoscA(myList, tab);
	}
	addToAList(myList, 6);
	cout << "Dodanie elementu 5 na koniec: " << "Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4, 6 };
		sprawdzPoprawnoscA(myList, tab);
	}
	addToAList(myList, 7);
	cout << "Dodanie elementu 5 na koniec: " << "Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4, 6, 7 };
		sprawdzPoprawnoscA(myList, tab);
	}
	cout << "Test iteratora: ";
	{
		int tab[] = { 0, 1, 3, 4, 6, 7 };
		auto iter = getAIterator(myList);
		int value = iterateA(iter.get());
		int i = 0;
		bool blad = 0;
		while (value != NaN) {
			//cout << value << endl;
			value = iterateA(iter.get());
			blad = value == tab[i];
			i++;
			if (blad) break;
		}
		if (blad) {
			cout << "!!! BLAD !!!" << endl;
		}
		else {
			cout << "OK" << endl;
		}
	}
	
}