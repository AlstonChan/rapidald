#include<iostream>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

Cart_Response input_validation(bool is_ala_cart, int sets_drinks_id, int sets_snacks_id);
bool cart_add_item(Cart item);

Cart_Response cart_add(
	int food_num,
	int quantity,
	int price,
	bool is_ala_cart,
	int sets_drinks_id,
	int sets_snacks_id
) {
	Cart_Response input_validation(bool is_ala_cart, int sets_drinks_id, int sets_snacks_id);

	Cart item;

	if (cart_size == 100) {
		Cart_Response failure = {
			"The cart is full, unable to perform action ADD",
			false
		};
		return failure;
	}

	item.food_id = food_num;
	item.quantity = quantity;
	item.price = price;
	item.is_ala_cart = is_ala_cart;
	item.sets_drinks_id = sets_drinks_id;
	item.sets_snacks_id = sets_snacks_id;

	bool add_success = cart_add_item(item);

	if (add_success) {
		Cart_Response success = {
			(is_ala_cart
				?
				"Item " + menu_list_item[food_num][0]
				:
				"Item " + menu_list_item[food_num][0] + " with " +
				menu_list_item[sets_drinks_id][0] + " & " +
				menu_list_item[sets_snacks_id][0]) + " added successfully"
			,
			true
		};
		return success;
	}
	else {
		Cart_Response failure = {
			"Error occurred when trying to add item " +
			(is_ala_cart
				?
				menu_list_item[food_num][0]
				:
				menu_list_item[food_num][0] + " with " +
				menu_list_item[sets_drinks_id][0] + " & " +
				menu_list_item[sets_snacks_id][0])
			,
			false
		};
		return failure;
	}
}

bool cart_add_item(Cart item) {
	if (item.is_ala_cart) {
		if (cart_size != 0) {
			for (size_t i = 0; i < cart_size; i++) {
				if (cart[i].is_ala_cart && cart[i].food_id == item.food_id) {
					cart[i] = item;
					break;
				} else if ((i + 1) == cart_size) {
					// Add item to the cart
					cart[cart_size] = item;
					cart_size++;
				}
			}
		} else {
			// Add item to the cart
			cart[cart_size] = item;
			cart_size++;
		}

	} else {
		// Add item to the cart
		cart[cart_size] = item;
		cart_size++;
	}
	return true;
}