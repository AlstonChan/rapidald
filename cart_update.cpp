#include<iostream>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

Cart_Response input_validation(bool is_ala_cart, int sets_drinks_id, int sets_snacks_id);
bool cart_update_item(Cart item, int cart_id);

Cart_Response cart_update(int quantity,int cart_id_to_update) {

	Cart_Response input_validation(bool is_ala_cart, int sets_drinks_id, int sets_snacks_id);

	Cart item;
	int food_num = cart[cart_id_to_update].food_id;
	int is_ala_cart = cart[cart_id_to_update].is_ala_cart;

	item.food_id = food_num;
	item.quantity = quantity;
	item.price = is_ala_cart
		? quantity * stol(menu_list_item[food_num][2])
		: quantity * (stol(menu_list_item[food_num][2]) + 6);
	item.is_ala_cart = is_ala_cart;
	item.sets_drinks_id = cart[cart_id_to_update].sets_drinks_id;
	item.sets_snacks_id = cart[cart_id_to_update].sets_snacks_id;

	bool update_success = cart_update_item(item, cart_id_to_update);

	if (update_success) {
		Cart_Response success = {
			(is_ala_cart
				?
				"Item " + menu_list_item[food_num][0]
				:
				"Item " + menu_list_item[food_num][0] + " with " +
				menu_list_item[cart[cart_id_to_update].sets_drinks_id][0] + " & " +
				menu_list_item[cart[cart_id_to_update].sets_snacks_id][0]) + " update successfully"
			,
			true
		};
		return success;
	}
	else {
		Cart_Response failure = {
			"Error occurred when trying to update item " +
			(is_ala_cart
				?
				menu_list_item[food_num][0]
				:
				menu_list_item[food_num][0] + " with " +
				menu_list_item[cart[cart_id_to_update].sets_drinks_id][0] + " & " +
				menu_list_item[cart[cart_id_to_update].sets_snacks_id][0])
			,
			false
		};
		return failure;
	}
}

bool cart_update_item(Cart item, int cart_id) {
	// Add item to the cart
	cart[cart_id] = item;
	return true;
}