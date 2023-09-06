#include<iostream>
#include<limits>
#include<string>

#include "menu_list.h"

using namespace std;

void header(void);
void menu_entry(void);
void menu_update_cart(int food_num);
void food_selection_quantity(int& order_quantity);
void handleInvalid(string text, int& input);

void food_selection(int option_num) {

	unsigned int menu_id = option_num - 1;
	int wait = 0;
	int order_quantity = 0;
	int user_options = 0;
	char meal_option = 0;

	int drinks_selection = 0;
	int snacks_selection = 0;

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

			while (cin.fail()) {
				handleInvalid("Select a drinks: ", drinks_selection);
			}

			// using handleInvalid cause infinite loop
			while (drinks_selection < 1 || drinks_selection > 3) {
				handleInvalid("Select a drinks :", drinks_selection);
			}

			cout << "\nDrinks selected: \n" << menu_list_item[drinks_selection + 9][0] << "\n\n";

			for (size_t i = 1; i < 3; i++) {
				cout << i << ". " << menu_list_item[i + 13][0] << "\n";
			}
			cout << "Select a snacks: ";
			cin >> snacks_selection;

			while (cin.fail()) {
				handleInvalid("Select a snacks: ", snacks_selection);
			}

			while (snacks_selection < 1 || snacks_selection > 2) {
				handleInvalid("Select a snacks :", snacks_selection);
			}

			cout << snacks_selection;

			cout << "\nSnacks selected: \n" << menu_list_item[snacks_selection + 13][0] << "\n";
		}

		food_selection_quantity(order_quantity);
	}

	// Summary of the input by the user
	cout << "\n\n----------Summary----------\n";

	// Option selections
	if (option_num >= 1 && option_num <= 9) {
		cout << "You have selected " << (meal_option == 'y' ? "set meal" : "ala cart") << "\n";
		cout << menu_list_item[menu_id][0] << " with " << menu_list_item[drinks_selection + 9][0] << " & " << menu_list_item[snacks_selection + 13][0] << "\n";
	}
	cout << "Quantity : " << order_quantity << " item\n";
	if (option_num >= 1 && option_num <= 9) {
		cout << "Price: RM " << (order_quantity * (stol(menu_list_item[menu_id][2]) + 6));
	} else
		cout << "Price: RM " << (order_quantity * stol(menu_list_item[menu_id][2]));
	cout << "\n\n----------Options----------\n";
	cout << "Enter 0 to back\n";
	cout << "Enter 1 to add to cart\n";
	cout << "\nEnter your input : ";

	cin >> user_options;

	while (cin.fail() || (user_options < 0 || user_options >= 2)) {
		handleInvalid("Enter your input : ", user_options);
	}

	if (user_options == 0) {
		menu_entry();
	} else if (user_options == 1) {
		menu_update_cart(option_num-1);
	}
}

void food_selection_quantity(int &order_quantity) {
	cout << "\nQuantity : ";
	cin >> order_quantity;

	while (cin.fail()) {
		handleInvalid("Quantity : ", order_quantity);
	}
}

void handleInvalid(string text, int &input) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, Please try again.";
		cout << "\n" << text;
		cin >> input;
}