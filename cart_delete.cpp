#include<iostream>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

Cart_Response input_validation(bool is_ala_cart, int sets_drinks_id, int sets_snacks_id);
bool cart_delete_item(int cart_id);

Cart_Response cart_delete(int cart_id_to_delete) {

	Cart_Response input_validation(bool is_ala_cart, int sets_drinks_id, int sets_snacks_id);

	Cart item;
	int food_num = cart[cart_id_to_delete].food_id;
	int is_ala_cart = cart[cart_id_to_delete].is_ala_cart;
	int quantity = cart[cart_id_to_delete].quantity;

	item.food_id = food_num;
	item.quantity = quantity;
	item.price = is_ala_cart
		? quantity * stol(menu_list_item[food_num][2])
		: quantity * (stol(menu_list_item[food_num][2]) + 6);
	item.is_ala_cart = is_ala_cart;
	item.sets_drinks_id = cart[cart_id_to_delete].sets_drinks_id;
	item.sets_snacks_id = cart[cart_id_to_delete].sets_snacks_id;

	bool delete_success = cart_delete_item(cart_id_to_delete);

	if (delete_success) {
		Cart_Response success = {
			(is_ala_cart
				?
				"Item " + menu_list_item[food_num][0]
				:
				"Item " + menu_list_item[food_num][0] + " with " +
				menu_list_item[item.sets_drinks_id][0] + " & " +
				menu_list_item[item.sets_snacks_id][0]) + " deleted successfully"
			,
			true
		};
		return success;
	}
	else {
		Cart_Response failure = {
			"Error occurred when trying to delete item " +
			(is_ala_cart
				?
				menu_list_item[food_num][0]
				:
				menu_list_item[food_num][0] + " with " +
				menu_list_item[item.sets_drinks_id][0] + " & " +
				menu_list_item[item.sets_snacks_id][0])
			,
			true
		};
		return failure;
	}
}

bool cart_delete_item(int cart_id) {
	// Add item to the cart
	cart[cart_id].food_id = -1;
	cart[cart_id].quantity = -1;
	cart[cart_id].price = -1;
	cart[cart_id].is_ala_cart = false;
	cart[cart_id].sets_drinks_id = -1;
	cart[cart_id].sets_snacks_id = -1;
	cart_size--;

	//TODO
	//Sort item after delete

	return true;
}