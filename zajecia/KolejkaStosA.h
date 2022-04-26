#pragma once
#include "ListA.h" // dostosuj sciezke do wlasnej instalacji materialow

//Kolejka:
void zakolejkujA(ListA* lista, int wartosc);  //Dodanie do kolejki
int odkolejkujA(ListA* lista); //Pobranie elementu z kolejki

//Stos
void wrzucNaStosA(ListA* lista, int wartosc); //Wrzycenie elementu na stos
int zdejmujZeStosuA(ListA* lista); //Pobranie elementu ze stosu

void KolejkaStosATest(); //Funkcja testująca