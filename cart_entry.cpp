#include<iostream>
#include<iomanip>
#include<string>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

void header(void);
void termination(void);
void cart_options(int &current_page, string &option, int &dining_option);
void cart_main_list(int current_page);

int cart_size = 0;

void cart_entry() {

	string option = "E";
	int current_page = 0;
	int dining_option = 0; // 1 for dine in, 2 for take away

	do {
		cout << "\033c";

		//header 
		header();

		// cart ui
		cart_main_list(current_page);

		// Options
		cart_options(current_page, option, dining_option);

		// continue to loop if option is not E or e/ M or m
	} while (isalpha(option[0]) ? tolower(option[0]) != 'e' && tolower(option[0]) != 'm': true);

	if (isalpha(option[0]) && tolower(option[0]) == 'e') {
		termination();
	}
}

void cart_main_list(int current_page) {
	cout << setw(30) << left << setfill('-') << '-' << "\n";
	cout << setw(30) << setfill(' ') << "CART" << "\n";
	cout << setw(30) << setfill('-') << '-' << setfill('-') << "\n\n";

		if (cart_size == 0) {
			cout << "\nCart is empty\n\n\n";
		} else {
			int max_loop = cart_size <= (current_page + 1) * 9 ? cart_size - (current_page * 9) : 9;

			for (size_t i = 0; i < max_loop; i++) {
				unsigned int numbering = current_page * 9 + i;

				if (cart[numbering].is_ala_cart) {
					cout << numbering + 1 << ". " << menu_list_item[cart[numbering].food_id][0] << "\n";
				}
				else {
					cout << numbering + 1 << ". " << menu_list_item[cart[numbering].food_id][0] << " with ";
					cout << menu_list_item[cart[numbering].sets_drinks_id][0] << " & ";
					cout << menu_list_item[cart[numbering].sets_snacks_id][0] << " (Set meal)\n";
				}

				cout << (numbering + 1 > 9 ? "    " : "   ") << "Quantity: " << cart[numbering].quantity << "\n";
				cout << (numbering + 1 > 9 ? "    " : "   ") << "Price: RM " << cart[numbering].price << "\n\n";
			}

			int total_price = 0;
			for (size_t i = 0; i < cart_size; i++) {
				total_price += cart[i].price;
			}
			cout << "Total Price: RM " << total_price << "\n";
			cout << "Total Item: " << cart_size << "\n\n";
		}
			
}