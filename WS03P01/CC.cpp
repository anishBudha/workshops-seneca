//Name: Anish Budha
//Email : abudha@myseneca.ca
//Student Id : 174760215
//Date : 9 / 30 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "CC.h"
#include "Utils.h"


using namespace std;
namespace sdds {

	// Validate the credit card information
	bool CC::validate(const char* name,
		unsigned long long cardNo,
		short cvv,
		short expMon,
		short expYear)const {
		return name && strlen(name) > 2 &&
			cardNo >= 4000000000000000ll && cardNo <= 4099999999999999ll &&
			cvv >= 100 && cvv < 1000 &&
			expMon >= 1 && expMon <= 12 &&
			expYear >= 22 && expYear <= 32;
	}

	// Print the 16-digit number in a set of 4-digit numbers separated by spaces
	void CC::prnNumber()const {
		unsigned long long tmp = m_cardNo;
		const int N = 16;
		int num[N];
		for (int i = N - 1; i >= 0; i--) num[i] = tmp % 10, tmp /= 10;		// Convert the number to new array
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << num[i * 4 + j];		// Print the new array one by one digit
			}
			if (i < 3) cout << ' ';			// Print space between every 4 digits
		}
	}

	// Sets the object to a safe empty state
	void CC::set() {
		m_name = nullptr;
		m_cardNo = 0;
		m_cvv = 0;
		m_expMon = 0;
		m_expYear = 0;
	}

	void CC::cleanUp() {
		delete[] m_name;
		set();
	}

	bool CC::isEmpty()const {
		if (m_name == nullptr)
		{
			return true;
		}
		else return false;
	}

	void CC::set(const char* cc_name,
		unsigned long long cc_no,
		short cvv,
		short expMon,
		short expYear) {
		cleanUp();		// Cleanup the object
		if (validate(cc_name, cc_no, cvv, expMon, expYear)) {		// Check all the arguments using validate
			m_name = new char[strlen(cc_name) + 3];

			strcpy(m_name, cc_name);
			m_cardNo = cc_no;
			m_cvv = cvv; //using arrow operator to access cvv through the pointer
			m_expMon = expMon;
			m_expYear = expYear;


		}
	}

	// Read all the values from the console and if successful store the values to the object
	bool CC::read() {
		cleanUp();
		cout << "Card holder name: ";

		char name[71];
		if (!cin.getline(name, 71)) {	// Read name from console and if failed return false
			cin.clear();
			cin.ignore(256, '\n'); //using ignore() to avoid the input including the newline character
			return false;
		}
		cout << "Credit card number: ";
		if (!(cin >> m_cardNo)) {	// Read cardNo from console and if failed return false
			cin.clear();
			cin.ignore(256, '\n');
			return false;
		}
		cout << "Card Verification Value (CVV): ";
		if (!(cin >> m_cvv)) {	// Read card verification value from console and if failed return false
			cin.clear();
			cin.ignore(256, '\n');
			return false;
		}
		char m_date[50];
		cout << "Expiry month and year (MM/YY): ";
		if (!(cin >> m_date)) {	// Read expiry date from console and if failed return false
			cin.clear();
			cin.ignore(256, '\n');
			return false;
		}
		m_expMon = 0;
		m_expYear = 0;
		int i;

		// The separator can be any non-digit character to separate the month and year values.
		for (i = 0; m_date[i]; i++) {
			if (m_date[i] < '0' || m_date[i] > '9') break;
			m_expMon = m_expMon * 10 + m_date[i] - '0';
		}
		for (i++; m_date[i]; i++) {
			m_expYear = m_expYear * 10 + m_date[i] - '0';
		}
		if (!validate(m_name, m_cardNo, m_cvv, m_expMon, m_expYear)) return false;
		set(m_name, m_cardNo, m_cvv, m_expMon, m_expYear);
		return true;
	}

	// Print the object in example format
	void CC::display(int row) const {
		if (isEmpty()) {
			cout << "Invalid Credit Card Record\n";
			return;
		}
		if (row > 0) {
			string strName = m_name;
			cout << "|";
			cout << " " << setw(3) << row << " |";
			cout << " " << left << setw(30) << strName.substr(0, 30) << " |";
			cout << " ";
			prnNumber();
			cout << " | " << m_cvv << " | ";
			cout << right << setw(2) << m_expMon << '/' << m_expYear;
			cout << " |\n";
		}
		else {
			cout << "Name: " << m_name << endl;
			cout << "Creditcard No: ";
			prnNumber();
			cout << endl;
			cout << "Card Verification Value: " << m_cvv << endl;
			cout << "Expiry Date: " << m_expMon << '/' << m_expYear << endl;
		}
	}


};