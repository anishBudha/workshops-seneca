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