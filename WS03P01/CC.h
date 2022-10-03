//Name: Anish Budha
//Email : abudha@myseneca.ca
//Student Id : 174760215
//Date : 9 /  / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CC_H 
#define SDDS_CC_H
#pragma once

namespace sdds {
	class CC {
	private:
		bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const;
		void prnNumber()  const;
		char* m_name;
		unsigned long long m_cardNo;
		short m_cvv, m_expMon, m_expYear;

	public:
		void set();
		void cleanUp();
		bool isEmpty()const;
		void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);
		bool read();
		void display(int row = 0) const;
	};
}

#endif