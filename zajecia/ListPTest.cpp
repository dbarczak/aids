#include <iostream>
#include "Common.h"
#include "ListP.h"
#include "ListPTest.h"

using namespace std;

//Wypisanie elementów listy
void printPList(ListP* list) {
	Element* curr = list->first;
	if (curr == NULL) {
		cout << "Lista jest pusta" << endl;
	}
	else {
		while (curr->next != NULL) {
			cout << curr->value << endl;
			curr = curr->next;
		}
		cout << curr->value << endl;
	}
}

//Sprawdzenie poprawności elementów listy
bool sprawdzPoprawnoscP(ListP* list, int poprawneElementyListy[]) {
	bool blad = 0;
	int curVal;
	for (int i = 0; i < sizeP(list); i++) {
		curVal = getFromPList(list, i);
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

//Test listy
void ListPTest() {
	cout << "Test lista wskaznikowa" << endl;
	ListP* myList = newPList();
	//Wypisanie elementów listy
	printPList(myList);
	//Dodanie elementów do listy
	addToPList(myList, 0);
	addToPList(myList, 1);
	addToPList(myList, 2);
	addToPList(myList, 3);
	addToPList(myList, 4);
	//Wypisanie elementów listy
	printPList(myList);
	//Zmienne testowe
	int odczyt;
	bool poprawnosc;
	//Test odczytów
	odczyt = getFromPList(myList, 2);
	poprawnosc = odczyt == 2;
	cout << "Odczytalem= " << odczyt << " Wynik=" << poprawnosc << endl;
	odczyt = getFromPList(myList, 4);
	poprawnosc = odczyt == 4;
	cout << "Odczytalem=" << odczyt << " Wynik=" << poprawnosc << endl;
	odczyt = getFromPList(myList, 5);
	poprawnosc = odczyt == NaN;
	cout << "Odczytalem=" << odczyt << " Wynik=" << poprawnosc << endl;
	//============= TEST USUWANIA ===============	
	int wyn, toRemove, sizePrzed, sizePo;
	toRemove = 2;
	sizePrzed = sizeP(myList);
	wyn = removeFromPList(myList, toRemove);
	sizePo = sizeP(myList);
	cout << "Usuwanie elementu o indeksie: " << toRemove << " Rozmiar zmienił sie poprawnie: " << (sizePo == sizePrzed - 1) << " Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4 };
		sprawdzPoprawnoscP(myList, tab);
	}
	//				
	addToPList(myList, 5);
	cout << "Dodanie elementu 5 na koniec: " << "Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4, 5 };
		sprawdzPoprawnoscP(myList, tab);
	}
	toRemove = 5;
	sizePrzed = sizeP(myList);
	wyn = removeFromPList(myList, toRemove);
	sizePo = sizeP(myList);
	cout << "Usuwanie elementu o indeksie: " << toRemove << "  Rozmiar zmienił sie poprawnie: " << (sizePo == sizePrzed) << " Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4, 5 };
		sprawdzPoprawnoscP(myList, tab);
	}
	toRemove = 4;
	sizePrzed = sizeP(myList);
	wyn = removeFromPList(myList, toRemove);
	sizePo = sizeP(myList);
	cout << "Usuwanie elementu o indeksie: " << toRemove << "  Rozmiar zmienił sie poprawnie: " << (sizePo == sizePrzed - 1) << " Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4 };
		sprawdzPoprawnoscP(myList, tab);
	}
	addToPList(myList, 6);
	cout << "Dodanie elementu 5 na koniec: " << "Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4, 6 };
		sprawdzPoprawnoscP(myList, tab);
	}
	addToPList(myList, 7);
	cout << "Dodanie elementu 5 na koniec: " << "Wynik testu: ";
	{
		int tab[] = { 0, 1, 3, 4, 6, 7 };
		sprawdzPoprawnoscP(myList, tab);
	}
	cout << "Test iteratora: ";
	{
		int tab[] = { 0, 1, 3, 4, 6, 7 };
		auto iter = getPIterator(myList);
		int value = iterateP(iter.get());
		int i = 0;
		bool blad = 0;
		while (value != NaN) {
			//cout << value << endl;
			value = iterateP(iter.get());
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

