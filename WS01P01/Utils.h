//Name: Anish Budha
//Email : abudha@myseneca.ca
//Student Id : 174760215
//Date : 9 / 16 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef sdds_Utils_H 
#define sdds_Utils_H

namespace sdds {
	void flushkeys();
	bool yes();
	bool ValidYesResponse(char ch);
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);

}

#endif