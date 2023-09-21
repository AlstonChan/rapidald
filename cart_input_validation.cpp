#include<iostream>

#include "cart_var.h"

using namespace std;

Cart_Response input_validation(bool is_ala_cart, int sets_drinks_id, int sets_snacks_id) {
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
}