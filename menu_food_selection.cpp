#include<iostream>
#include<limits>
#include<string>

#include "menu_list.h"

using namespace std;

void header(void);
void menu_entry(void);
void menu_update_cart(int food_num);

void food_selection(int option_num) {

	int wait = 0;
	int order_quantity = 0;
	int user_options = 0;

	cout << "\033c";

	//header 
	header();

	cout << menu[option_num-1][0] << "\n";
	cout << menu[option_num-1][1] << "\n";
	cout << "RM " << menu[option_num - 1][2] << "\n";

	// If food is Drinks or Snacks
	if (option_num >=10 && option_num <=18) {
		// select quantity
		cout << "\nQuantity : ";
		cin >> order_quantity;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, Please try again.";
			cout << "\nQuantity : ";
			cin >> order_quantity;
		}
	}

	// Summary of the input by the user
	cout << "\n\n----------Summary----------\n";

	// Option selections
	cout << "You have selected " << order_quantity << " item.\n";
	cout << "\n\n----------Options----------\n";
	cout << "Enter 0 to back\n";
	cout << "Enter 1 to add to cart\n";
	cout << "\nEnter your input : ";

	cin >> user_options;

	while (cin.fail() || (user_options < 0 || user_options >= 2)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, Please try again.";
		cout << "\nEnter your input : ";
		cin >> user_options;
	}

	if (user_options == 0) {
		menu_entry();
	} else if (user_options == 1) {
		menu_update_cart(option_num-1);
	}

}