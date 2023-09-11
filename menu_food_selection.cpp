#include<iostream>
#include<limits>
#include<string>
#include <chrono>
#include <thread>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

void header(void);
Cart_Response cart_add(
	int food_num,
	int quantity,
	int price,
	bool is_ala_cart,
	int sets_drinks_id,
	int sets_snacks_id
);
void handle_invalid(string text, int& input);

void food_selection_quantity(int& order_quantity);
void handle_invalid(string text, int& input);

void menu_food_selection(int option_num) {
	unsigned int menu_id = option_num - 1;
	int order_quantity = 0; // the quantity of the food/ meal set
	int user_options = 0; // 0 -> cancel current meal, 1 -> add current meal to cart
	char meal_option = 0; // Y/y -> set meal, N/n -> ala cart
	int drinks_selection = -1; // only valid if meal_option is set meal (Y/y)
	int snacks_selection = -1; // only valid if meal_option is set meal (Y/y)

	cout << "\033c";

	//header 
	header();

	cout << menu_list_item[menu_id][0] << "\n";
	cout << menu_list_item[menu_id][1] << "\n";
	cout << "RM " << menu_list_item[menu_id][2] << "\n";

	// If food is Drinks or Snacks
	if (option_num >= 10 && option_num <= 18)
		food_selection_quantity(order_quantity);
	
	// If food is main food
	if (option_num >= 1 && option_num <= 9) {
		// select Ala cart or set meal
		cout << "\nDo you want a set meal or ala cart (Y\\n): ";
		cin >> meal_option;

		// Invalid input if meal_option is not alphabet or meal_option is not equal to y or n
		while(!isalpha(meal_option) || isalpha(meal_option) && (tolower(meal_option) != 'y' && tolower(meal_option) != 'n')) {
			cout << "Invalid input, Please try again.";
			cout << "\nDo you want a set meal or ala cart (Y\\n): ";
			cin >> meal_option;
		}

		if (tolower(meal_option) == 'y') {
			cout << "\n";
			for (size_t i = 1; i < 4; i++) {
				cout << i << ". " << menu_list_item[i+9][0] << "\n";
			}
			cout << "Select a drinks: ";
			cin >> drinks_selection;

			while (cin.fail() || (drinks_selection < 1 || drinks_selection > 3)) {
				handle_invalid("Select a drinks: ", drinks_selection);
			}

			cout << "\nDrinks selected: \n" << menu_list_item[drinks_selection + 9][0] << "\n\n";

			for (size_t i = 1; i < 3; i++) {
				cout << i << ". " << menu_list_item[i + 13][0] << "\n";
			}
			cout << "Select a snacks: ";
			cin >> snacks_selection;

			while (cin.fail() || (snacks_selection < 1 || snacks_selection > 2)) {
				handle_invalid("Select a snacks: ", snacks_selection);
			}

			cout << "\nSnacks selected: \n" << menu_list_item[snacks_selection + 13][0] << "\n";
		}

		food_selection_quantity(order_quantity);
	}

	// Summary of the input by the user
	cout << "\n\n----------Summary----------\n";

	// Option selections
	if (option_num >= 1 && option_num <= 9) {
		cout << "You have selected " << (tolower(meal_option) == 'y' ? "set meal" : "ala cart") << "\n";
		if (tolower(meal_option) == 'y') {
			cout << menu_list_item[menu_id][0] << " with ";
			cout << menu_list_item[drinks_selection + 9][0] << " & ";
			cout << menu_list_item[snacks_selection + 13][0] << "\n";
		} else cout << menu_list_item[menu_id][0] << "\n";
	}
	cout << "Quantity : " << order_quantity << " item\n";
	if (option_num >= 1 && option_num <= 9) {
		if (tolower(meal_option) == 'y')
			cout << "Price: RM " << (order_quantity * (stol(menu_list_item[menu_id][2]) + 6));
		else
			cout << "Price: RM " << order_quantity* stol(menu_list_item[menu_id][2]);
	} else
		cout << "Price: RM " << order_quantity * stol(menu_list_item[menu_id][2]);
	cout << "\n\n----------Options----------\n";
	cout << "Enter 0 to cancel\n";
	cout << "Enter 1 to add to cart\n";
	cout << "\nEnter your input : ";

	cin >> user_options;

	while (cin.fail() || (user_options < 0 || user_options >= 2)) {
		handle_invalid("Enter your input : ", user_options);
	}

	// if user wants to add current meal to cart
	if (user_options == 1) {
		// if current meal is set meal
		if (tolower(meal_option) == 'y') {
			Cart_Response res = cart_add(
				option_num - 1, 
				order_quantity, 
				order_quantity * (stol(menu_list_item[menu_id][2]) + 6), 
				false,
				drinks_selection + 9,
				snacks_selection + 13
			);
			cout << res.message;
			this_thread::sleep_for(chrono::seconds(2));
		} // else current meal is ala cart
		else {
			Cart_Response res = cart_add(
				option_num - 1,
				order_quantity,
				order_quantity * stol(menu_list_item[menu_id][2]),
				true,
				-1,
				-1
			);
			cout << res.message;
			this_thread::sleep_for(chrono::seconds(2));
		}
	}
}

void food_selection_quantity(int &order_quantity) {
	cout << "\nQuantity : ";
	cin >> order_quantity;

	while (cin.fail() || order_quantity <= 0) {
		handle_invalid("Quantity : ", order_quantity);
	}
}
