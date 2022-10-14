#pragma once
#ifndef SDDS_TOURBUS_H__
#define SDDS_TOURBUS_H__
#include "TourTicket.h"

using namespace std;
namespace sdds {
	class TourBus
	{
	private:
		TourTicket* m_passengers;
		int	m_capacity;
		bool m_boarded;
	public:
		TourBus(int m_passengers);
		~TourBus();
		bool validTour() const;
		TourBus& board();
		void  startTheTour() const;

	};
}
#endif // !SDDS_TOURBUS_H__
