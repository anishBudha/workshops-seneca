//Name: Anish Budha
//Email : abudha@myseneca.ca
//Student Id : 174760215
//Date : 9 / 16 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_SHOPPINGREC_H 
#define SDDS_SHOPPINGREC_H

const int MAX_TITLE_LENGTH = 50;
const int MAX_QUANTITY_VALUE = 50;
namespace sdds {
	

	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};
	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);

}



#endif