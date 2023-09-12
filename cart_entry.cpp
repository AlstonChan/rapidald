#include<iostream>
#include<iomanip>
#include<string>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

void header(void);
void termination(void);
void cart_options(int &current_page, string &option);
void cart_main_list(int current_page);

int cart_size = 0;

void cart_entry() {

	string option = "E";
	int current_page = 0;

	do {
		cout << "\033c";

		//header 
		header();

		// cart ui
		cart_main_list(current_page);

		// Options
		cart_options(current_page, option);

		// continue to loop if option is not E or e/ M or m
	} while (isalpha(option[0]) ? tolower(option[0]) != 'e' && tolower(option[0]) != 'm' : true);

	if (isalpha(option[0]) && tolower(option[0]) == 'e') {
		termination();
	}
}

void cart_main_list(int current_page) {
	cout << setw(30) << left << setfill('-') << '-' << "\n";
	cout << setw(30) << setfill(' ') << "CART" << "\n";
	cout << setw(30) << setfill('-') << '-' << setfill('-') << "\n\n";

	if (cart_size <= 9) {
		if (cart_size == 0) {
			cout << "\nCart is empty\n\n\n";
		} else {
			for (size_t i = 0; i < cart_size; i++) {
				unsigned int numbering = current_page * 9 + i;

				if (cart[i].is_ala_cart) {
					cout << numbering + 1 << ". " << menu_list_item[cart[i].food_id][0] << "\n";
				}
				else {
					cout << numbering + 1 << ". " << menu_list_item[cart[i].food_id][0] << " with ";
					cout << menu_list_item[cart[i].sets_drinks_id][0] << " & ";
					cout << menu_list_item[cart[i].sets_snacks_id][0] << " (Set meal)\n";
				}

				cout << (numbering + 1 > 9 ? "    " : "   ") << "Quantity: " << cart[i].quantity << "\n";
				cout << (numbering + 1 > 9 ? "    " : "   ") << "Price: RM " << cart[i].price << "\n\n";
			}

			int total_price = 0;
			for (size_t i = 0; i < cart_size; i++) {
				unsigned int numbering = current_page * 9 + i;
				total_price += cart[i].price;
			}
			cout << "Total Price: RM " << total_price << "\n\n";
		}
			
	}
}