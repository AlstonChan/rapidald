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
	if ((cart_id + 1) != cart_size) 
		for (size_t i = cart_id + 1; i < cart_size; i++) {
			cart[cart_id].food_id = cart[i].food_id;
			cart[cart_id].quantity = cart[i].quantity;
			cart[cart_id].price = cart[i].price;
			cart[cart_id].is_ala_cart = cart[i].is_ala_cart;
			cart[cart_id].sets_drinks_id = cart[i].sets_drinks_id;
			cart[cart_id].sets_snacks_id = cart[i].sets_snacks_id;
		}
		
	cart[cart_size].food_id = -1;
	cart[cart_size].quantity = -1;
	cart[cart_size].price = -1;
	cart[cart_size].is_ala_cart = false;
	cart[cart_size].sets_drinks_id = -1;
	cart[cart_size].sets_snacks_id = -1;

	cart_size--;

	return true;
}