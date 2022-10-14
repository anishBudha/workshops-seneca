#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

namespace sdds {

	Seat::Seat() {
		m_passenger = nullptr;
		m_row = 0;
		m_letter = '\0';
	}

	Seat& Seat::reset() {
		delete[] m_passenger;
		m_passenger = nullptr;
		m_row = 0;
		m_letter = '\0';
		return *this;

	}

	Seat::Seat(const char* passengerName) {
		if (passengerName == nullptr || passengerName[0] == '\0') {
			reset();
		}
		else {
			m_passenger = new char[strlen(passengerName) + 1];
			strcpy(m_passenger, passengerName);
			m_row = 0;
			m_letter = 0;
		}

	}


	Seat::Seat(const char* passengerName, int row, char letter) {
		if (passengerName == nullptr || passengerName[0] == '\0' || row < 1 || row > 99 || letter < 'A' || letter > 'Z') {
			m_passenger = nullptr;
			m_row = 0;
			m_letter = 0;
		}
		else {
			m_passenger = new char[strlen(passengerName) + 1];
			strcpy(m_passenger, passengerName);
			m_row = row;
			m_letter = letter;
		}

	}

	Seat::~Seat() {

		delete[] m_passenger;
		m_passenger = nullptr;

	}

	Seat& Seat::alAndCp(const char* str) {

		delete[] m_passenger;
		m_passenger = nullptr;

		if (str != nullptr && str[0] != '\0') {
			m_passenger = new char[strlen(str) + 1];
			strcpy(m_passenger, str);

		}

		return *this;

	}



	bool Seat::isEmpty()const {

		return (m_passenger == nullptr || m_passenger[0] == '\0');

	}

	bool Seat::assigned()const {

		return validate(m_row, m_letter);

	}

	Seat& Seat::set(int row, char letter) {

		if (validate(row, letter)) {
			m_row = row;
			m_letter = letter;
		}
		else {
			m_row = 0;
			m_letter = '\0';
		}

		return *this;

	}

	int Seat::row()const {

		return m_row;

	}

	char Seat::letter()const {

		return m_letter;

	}

	const char* Seat::passenger()const {

		return m_passenger;

	}

	std::ostream& Seat::display(std::ostream& coutRef)const {

		if (isEmpty()) {
			coutRef << "Invalid Seat!";
		}
		else {
			coutRef << setw(40);
			coutRef.fill('.');
			coutRef << left << m_passenger;
			coutRef.fill(' ');
			coutRef.unsetf(ios::left);
			if (row() == 0)
			{
				coutRef << " ___";
			}
			else
			{
				coutRef << " " << row() << letter();
			}
		}
		return coutRef;

	}

	std::istream& Seat::read(std::istream& cinRef) {

		reset();
		char name[70 + 1];
		int row;
		char letter;

		cinRef.getline(name, 70 + 1, ',');
		cinRef >> row >> letter;

		if (!cinRef.fail()) {
			if (name[0] != '\0') {
				alAndCp(name);
			}
			set(row, letter);
		}

		cinRef.clear();
		cinRef.ignore(1000, '\n');

		return cinRef;

	}

	bool Seat::validate(int row, char letter)const {

		bool result = false;

		if (row >= 1 && row <= 4) {
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F') {
				result = true;
			}
		}
		else if (row >= 7 && row <= 15) {
			if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F') {
				result = true;
			}
		}
		else if (row >= 20 && row <= 38) {
			if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F') {
				result = true;
			}
		}

		return result;

	}

	std::ostream& operator<<(std::ostream& coutRef, const Seat& seatRef) {

		return seatRef.display(coutRef);

	}

	std::istream& operator>>(std::istream& cinRef, Seat& seatRef) {

		return seatRef.read(cinRef);

	}

}