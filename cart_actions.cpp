#include<iostream>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

void header(void);
bool cart_add_item(Cart item);
bool cart_update_item(Cart item);

Cart_Response cart_actions(
	int food_num,
	int quantity,
	int price,
	bool is_ala_cart,
	int sets_drinks_id,
	int sets_snacks_id,
	enum actions cart_action
) {
	// catch incorrect input
	if (is_ala_cart && (sets_drinks_id != -1 || sets_snacks_id != -1)) {
		Cart_Response failure = {
			"Meal is ala cart but have sets drinks or snacks selected",
			false
		};
		return failure;
	}
	if (!is_ala_cart && (sets_drinks_id == -1 || sets_snacks_id == -1)) {
		Cart_Response failure = {
			"Meal is set meal but is missing either sets drinks or snacks",
			false
		};
		return failure;
	}

	if (is_ala_cart) {
		Cart ala_cart_item;

		switch (cart_action) {
		case ADD: {
			if (cart_size == 100) {
				Cart_Response failure = {
					"The cart is full, unable to perform action ADD",
					false
				};
				return failure;
			}

			ala_cart_item.food_id = food_num;
			ala_cart_item.quantity = quantity;
			ala_cart_item.price = price;
			ala_cart_item.is_ala_cart = is_ala_cart;
			ala_cart_item.sets_drinks_id = sets_drinks_id;
			ala_cart_item.sets_snacks_id = sets_snacks_id;

			bool add_success = cart_add_item(ala_cart_item);

			if (add_success) {
				Cart_Response success = {
					"Item " + menu_list_item[food_num][0] + " added successfully",
					true
				};
				return success;
			}
			else {
				Cart_Response failure = {
					"Error occurred when trying to add item " + menu_list_item[food_num][0],
					true
				};
				return failure;
			}
		}

		case UPDATE: {
			ala_cart_item.food_id = food_num;
			ala_cart_item.quantity = quantity;
			ala_cart_item.price = price;
			ala_cart_item.is_ala_cart = is_ala_cart;
			ala_cart_item.sets_drinks_id = sets_drinks_id;
			ala_cart_item.sets_snacks_id = sets_snacks_id;

			bool update_success = cart_update_item(ala_cart_item);

			if (update_success) {
				Cart_Response success = {
					"Item " + menu_list_item[food_num][0] + " update successfully",
					true
				};
				return success;
			}
			else {
				Cart_Response failure = {
					"Error occurred when trying to update item " + menu_list_item[food_num][0],
					true
				};
				return failure;
			}
		}
		}
	}
	else {
		// set meal here
	}
}

bool cart_add_item(Cart item) {
	// Add item to the cart
	cart[cart_size] = item;
	cart_size++;
	return true;
}

bool cart_update_item(Cart item) {
	// Add item to the cart
	cart[cart_size] = item;
	return true;
}