#include<iostream>
#include<string>
#include <chrono>
#include <thread>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

void header(void);
void handle_invalid(string text, int& input);
Cart_Response cart_update(int quantity,int cart_num_to_update);
Cart_Response cart_delete(int cart_id_to_delete);

void cart_item_selection(int cart_num) {

	unsigned int cart_id = cart_num - 1;
	int user_options = 0; // 0 -> cancel current meal, 1 -> add current meal to cart

	cout << "\033c";

	//header 
	header();

	if (!cart[cart_id].is_ala_cart) {
		cout << menu_list_item[cart[cart_id].food_id][0] << " with ";
		cout << menu_list_item[cart[cart_id].sets_drinks_id][0] << " & ";
		cout << menu_list_item[cart[cart_id].sets_snacks_id][0] << "\n";
		cout << "RM " << cart[cart_id].quantity * (stoi(menu_list_item[cart[cart_id].food_id][2]) + 6);
		cout << "(Set meal) \n";
	}
	else {
		cout << menu_list_item[cart[cart_id].food_id][0] << "\n";
		cout << menu_list_item[cart[cart_id].food_id][1] << "\n";
		cout << "RM " << menu_list_item[cart[cart_id].food_id][2] << "\n";
	}

	// Option selections
	cout << "\n\n----------Options----------\n";
	cout << "Enter 0 to cancel edit\n";
	cout << "Enter 1 to update quantity\n";
	cout << "Enter 2 to remove item from cart\n";
	cout << "\nEnter your input : ";

	cin >> user_options;

	while (cin.fail() || (user_options < 0 || user_options >= 3)) {
		handle_invalid("Enter your input : ", user_options);
	}

	switch (user_options) {
		case 0: 
			break;
		case 1: {
			int quantity;

			cout << "\nQuantity : ";
			cin >> quantity;

			while (cin.fail()) {
				handle_invalid("Quantity : ", quantity);
			}

			Cart_Response res = cart_update(quantity,cart_id);
			cout << res.message;
			this_thread::sleep_for(chrono::seconds(2));
		}
			break;
		case 2:
			Cart_Response res = cart_delete(cart_id);
			cout << res.message;
			this_thread::sleep_for(chrono::seconds(2));
			break;
	}
}