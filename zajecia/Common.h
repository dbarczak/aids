#pragma once
#include <string>

const int NaN = -2000000000;

void wypiszTablice(int* tab, int tabSize);
bool porownajTablice(int* tab1, int sizeTab1, int* tab2, int sizeTab2);
int hashCode(std::string s);