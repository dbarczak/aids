#include <iostream>
#include <chrono>
#include "Common.h"
#include "KolejkaStosP.h"

using namespace std;

void zakolejkujP(ListP* lista, int wartosc) {
	//Tutaj dokonaj implementacji funkcji
}

int odkolejkujP(ListP* lista) {
	//Tutaj dokonaj implementacji funkcji
	return 0;
}

void wrzucNaStosP(ListP* lista, int wartosc) {
	Element* nowy = lista->first;
	Element* poprzedni = lista->first;
	if (lista->first == NULL)
	{
		lista->first = nowy;
	}
	if (lista->last == NULL)
	{
		lista->last = nowy;
	}
	else
	{
		poprzedni = lista->last;
		lista->last = nowy;
		poprzedni->next = lista->last;
	}
}

int zdejmujZeStosuP(ListP* lista) {
	//Tutaj dokonaj implementacji funkcji
	return 0;
}

void KolejkaStosPTest() {
	cout << "Test kolejka-stos z lista wskaznikowa" << endl;
	int numRep = 10000;
	ListP* kolejka = newPList();
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < numRep; i++) {
		zakolejkujP(kolejka, i);
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	bool chk = true;
	for (int i = 1; i < numRep; i++) {
		int val = odkolejkujP(kolejka);
		if (val != i) {
			chk = false;
			break;
		}
	}
	auto t3 = std::chrono::high_resolution_clock::now();
	cout << " Wynik: " << (chk ? "OK" : "Blad") << endl;

	auto t21 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	auto t32 = std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count();
	cout << "Czas wykonania: " << t21 << " | " << t32 << endl;

	destroyPList(kolejka);

	ListP* stos = newPList();
	auto st1 = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < numRep; i++) {
		wrzucNaStosP(stos, i);
	}
	auto st2 = std::chrono::high_resolution_clock::now();
	bool chkS = true;
	for (int i = numRep - 1; i > 0; i--) {
		int val = zdejmujZeStosuP(stos);
		if (val != i) {
			chkS = false;
			break;
		}
	}
	auto st3 = std::chrono::high_resolution_clock::now();
	cout << " Stos wynik: " << (chkS ? "OK" : "Blad") << endl;

	auto st21 = std::chrono::duration_cast<std::chrono::microseconds>(st2 - st1).count();
	auto st32 = std::chrono::duration_cast<std::chrono::microseconds>(st3 - st2).count();
	cout << "Czas wykonania: " << st21 << " | " << st32 << endl;

	destroyPList(stos);
}