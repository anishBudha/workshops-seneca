#define _CRT_SECURE_NO_WARNINGS
#include "TourBus.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

namespace sdds {

	TourBus::TourBus(int passengers)
	{
		m_capacity = passengers;
		m_boarded = false;
		m_passengers = new TourTicket[passengers];
	}

	TourBus::~TourBus()
	{
		delete[] m_passengers;
	}

	bool TourBus::validTour() const
	{
		return ((m_capacity == 4 || m_capacity == 16 || m_capacity == 22) && m_passengers != nullptr);
	}

	TourBus& TourBus::board()
	{
		if (validTour() && !m_boarded)
		{
			cout << "Boarding " << m_capacity << " Passengers:" << endl;
			for (int i = 0; i < m_capacity; i++)
			{
				char name[41];
				cout << i + 1 << "/" << m_capacity << "- Passenger Name: ";
				cin.getline(name, 41);
				m_passengers[i].issue(name);
			}
			m_boarded = true;
		}
		return *this;
	}

	void TourBus::startTheTour() const
	{
		if (validTour() && m_boarded)
		{
			cout << "Starting the tour...." << endl;
			cout << "Passenger List:" << endl;
			cout << "|Row | Passenger Name                           | Num |" << endl;
			cout << "+----+------------------------------------------+-----+" << endl;
			for (int i = 0; i < m_capacity; i++) {
				cout << "|" << setw(3) << i + 1 << " ";
				cout << left;
				m_passengers[i].display(cout);
				cout << endl;
			}
			cout << "+----+------------------------------------------+-----+" << endl;
		}
		else {
			cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
		}

	}
}
