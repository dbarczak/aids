#pragma once
#include "ListP.h" // dostosuj sciezke do wlasnej instalacji materialow

//Kolejka:
void zakolejkujP(ListP* lista, int wartosc); //Dodanie do kolejki
int odkolejkujP(ListP* lista); //Pobranie elementu z kolejki

//Stos
void wrzucNaStosP(ListP* lista, int wartosc); //Wrzycenie elementu na stos
int zdejmujZeStosuP(ListP* lista); //Pobranie elementu ze stosu

void KolejkaStosPTest(); //Funkcja testująca