#ifndef SDDS_SEAT_H__
#define SDDS_SEAT_H__
#include <iostream>
#include <iomanip>
#include <cstring>
namespace sdds {
	class Seat {
		char* m_passenger;
		int m_row;
		char m_letter;
		bool validate(int row, char letter)const;
		Seat& alAndCp(const char* str);
	public:
		Seat();
		Seat(const char* passengerName);
		Seat(const char* passengerName, int row, char letter);
		~Seat();
		Seat& reset();
		bool isEmpty() const;
		bool assigned() const;
		Seat& set(int row, char letter);
		int row()const;
		char letter()const;
		const char* passenger()const;
		std::ostream& display(std::ostream& coutRef = std::cout)const;
		std::istream& read(std::istream& cinRef = std::cin);
	};
	std::ostream& operator<<(std::ostream& coutRef, const Seat& seatRef);
	std::istream& operator>>(std::istream& cinRef, Seat& seatRef);
}
#endif // !SDDS_SEAT_H

