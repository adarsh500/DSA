#include <bits/stdc++.h>
#include "hashheader.h"
using namespace std;

int main(){
	Hashtable<int> priceMenu;

	priceMenu.insert("Burger", 120);
	priceMenu.insert("Pepsi", 20);	
	priceMenu.insert("BurgerPizza", 150);
	priceMenu.insert("Noodles", 25);
	priceMenu.insert("Cake", 40);

	priceMenu.print();

	// int* price = priceMenu.search("Noodles");
	// if (price == NULL){
	// 	cout << "Item not found" << endl;
	// 	//its *price as price is a pointer and we are dereferencing it
	// } else {
	// 	cout << "Price of Nachos is: " << *price << endl;;
	// }

}