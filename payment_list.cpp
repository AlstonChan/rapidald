#include<iostream>
#include<iomanip>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

void header(void);
void handle_invalid(string text, int& input);
void top_up(void);

void payment_list(int& option_pay, double total_price) {

	int option = 0;

	while (option != 3) {
		cout << "\033c";

		header();

		cout << setw(84) << left << setfill(' ') << "Item" << setw(10) << "Price" << setw(8) << "Quantity" << endl;

		for (size_t i = 0; i < cart_size; i++) {
			int numbering = i + 1;

			cout << left << numbering << (numbering >= 10 ? ". " : ".  ") ;

			if (!cart[i].is_ala_cart) {
				cout << setw(80) << menu_list_item[cart[i].food_id][0]
					+ " with " + menu_list_item[cart[i].sets_drinks_id][0] 
					+ " & " + menu_list_item[cart[i].sets_snacks_id][0]
					+ " (Set meal)";
			} else {
				cout << setw(80) << menu_list_item[cart[i].food_id][0];
			}

			cout << left << "RM" << fixed << setprecision(2) << setw(8) << (double) cart[i].price << setw(8) << cart[i].quantity << endl;

		}

		double total_price = 0;
		for (size_t i = 0; i < cart_size; i++) {
			total_price += cart[i].price;
		}
		cout << "\n\n";
		cout << setw(16) << setfill(' ') << left << "Sub Total" << " : " << "RM" << fixed << setprecision(2) << total_price << endl;

		//cout << "\nTotal Price : RM" << fixed << setprecision(2) << total_price;
		cout << setw(16) << left << (option_pay == 1 ? "Service Charge" : "Packaging Price") << " : " 
			<< (option_pay == 1 ? "(%) " : "RM") << fixed << setprecision(2)
			<< (option_pay == 1 ? SERVICE_CHARGE : (double)PACKAGING_PRICE) << endl;
		cout << setw(16) << left << "Total Price" << " : " << "RM" << fixed << setprecision(2)
			<< (option_pay == 1 ? (total_price + (total_price * SERVICE_CHARGE)) : (total_price + PACKAGING_PRICE)) << endl;

		cin >> option;
		// TODO
	}
}