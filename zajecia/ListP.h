#pragma once
#include <memory>

struct Element {//Pojedynczy element listy
	int value; //Przechowywana wartość
	Element* next; //Wskaźnik do następnego elementu listy
};

struct ListP { //Struktura opisująca listę
	Element* first; //Pierwszy element listy
	Element* last;  //Ostatni element listy
	int rozmiar;    //Liczba elementów przechowywanych na liście
};

struct IteratorP { //Struktura opisująca iterator do listy
	ListP* list; //Wskaźnik do listy
	Element* curr; //Wskaźnik do aktualnego elementu
	int counter; //Licznik opisujący ilość przeiterowanych elementów
};

ListP* newPList(); //Stworzenie listy
void destroyPList(ListP* list); //Usunięcie listy
void addToPList(ListP* list, int value); //Dodanie nowej wartości  do listy
int getFromPList(ListP* list, int index); //Odczytanie elementu o indeksie index
int removeFromPList(ListP* list, int index); //Usunięcie elementu o indeksie index z listy
int sizeP(ListP* list); //Zwraca rozmiar listy
void printPList(ListP* list); //Wypisuje elementy listy na ekranie

std::auto_ptr<IteratorP> getPIterator(ListP* list); //Pobranie iteratora do listy
int iterateP(IteratorP* iterator); //Odczytanie kolejnego elementu z listy