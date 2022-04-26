#include <iostream>
#include <chrono>
#include "Common.h"
#include "KolejkaStosA.h"
#include "ListA.h"

using namespace std;

void zakolejkujA(ListA* lista, int wartosc) {
	if (lista->counter == lista->tabSize)
	{
		lista->tabSize = lista->tabSize * 2;
		int* tab1 = new int[lista->tabSize];
		for (int i = 0; i < lista->tabSize; i++)
		{
			tab1[i] = lista->tab[i];
			if (lista->tab[i + 1] == NULL)
			{
				break;
			}
		}
		delete[] lista->tab;
		lista->tab = tab1;
	}
	lista->tab[lista->tabSize-1] = wartosc;
	for (int i = 0;i > lista->tabSize - 1;i--)
	{
		if (lista->tab[i] == NULL)
		{
			break;
		}
		lista->tab[i] = lista->tab[i + 1];
	}
}

int odkolejkujA(ListA* lista) {
	int wynik = lista->tab[0];
	for (int i = 0;i > lista->tabSize-1;i--)
	{
		if (lista->tab[i] == NULL)
		{
			break;
		}
		lista->tab[i] = lista->tab[i + 1];
	}
	return wynik;
}

void wrzucNaStosA(ListA* lista, int wartosc) {
	lista->tab[lista->counter] = wartosc;
	lista->counter++;
}

int zdejmujZeStosuA(ListA* lista) {
	int index = lista->counter;
	int wynik = lista->tab[index];
	int j = index + 1;
	while (j < lista->counter)
	{
		lista->tab[j - 1] = lista->tab[j];
		j++;
	}
	lista->counter = lista->counter - 1;
	return wynik;
}

void KolejkaStosATest() {
	cout << "Test kolejka-stos z lista tablicowa" << endl;
	int numRep = 10000;
	ListA* kolejka = newAList();
	auto t1 = std::chrono::high_resolution_clock::now();		
	for (int i = 1; i < numRep; i++) {
		zakolejkujA(kolejka, i);
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	bool chk = true;
	for (int i = 1; i < numRep; i++) {
		int val = odkolejkujA(kolejka);
		if (val != i) {
			chk = false;
			break;
		}
	}
	auto t3 = std::chrono::high_resolution_clock::now();
	cout << " Kolejka wynik: " << (chk ? "OK" : "Blad") << endl;

	auto t21 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	auto t32 = std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count();
	cout << "Czas wykonania: " << t21 << " | " << t32 << endl;

	destroyAList(kolejka);

	ListA* stos = newAList();
	auto st1 = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < numRep; i++) {
		wrzucNaStosA(stos, i);
	}
	auto st2 = std::chrono::high_resolution_clock::now();
	bool chkS = true;
	for (int i = numRep-1; i > 0; i--) {
		int val = zdejmujZeStosuA(stos);
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

	destroyAList(stos);
}