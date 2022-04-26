#pragma once
#include <memory>

//Struktura opisująca listę
struct ListA {	
	int* tab;    //Wskaźnik do tablicy przechowującej dane
	int tabSize;    //Rozmiar tablicy
	int counter; //Liczba aktualnie zajętych miejsc w tablicy
};

//Struktura opisująca iterator
struct IteratorA { 
	ListA* list; //Wskaźnik do listy
	int counter; //Aktualna pozycja na liście
};

ListA* newAList();	//Zainicjowanie nowej listy
void destroyAList(ListA* list); //Usunięcie listy
void addToAList(ListA* list, int value); //Dodanie do listy list elementu value
int getFromAList(ListA* list, int index); //Odczytanie z listy elementu o określonym indeksie
int removeFromAList(ListA* list, int index); //Usunięcie z listy elementu o określonym indeksie
int sizeA(ListA* list); //Zwraca rozmiar listy

std::auto_ptr<IteratorA> getAIterator(ListA* list); //Pobranie iteratora po liście
int iterateA(IteratorA* iterator); //Odczytanie najstępnej wartości z listy względem aktualnej pozycji