#include <iostream>
#include "Common.h"

using namespace std;

void wypiszTablice(int* tab, int tabSize) {	
	cout << "[";
	for (int i = 0; i < tabSize; i++) {	
		cout << tab[i];
		if (i < tabSize - 1) {
			cout << " , ";
		}
	}
	cout << "]" << endl;
}

bool porownajTablice(int* tab1, int sizeTab1, int* tab2, int sizeTab2) {	
	if (sizeTab1 != sizeTab2) {
		return false;
	}	
	for (int i = 0; i < sizeTab1; i++) {
		if (tab1[i] != tab2[i]) return false;
	}
	return true;
}

int hashCode(string s)
{
	int hash = 0;
	for (char ch : s) {
		int chInt = (int)ch;
		hash += 71 * chInt;
	}
	return hash;
}

