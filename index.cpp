#include<iostream>

#include "cart_var.h"

using namespace std;

void register_membership(void);

Cart cart[100] = {};

const double SERVICE_CHARGE = 0.1;
const int PACKAGING_PRICE = 2;

int main() {

	for (size_t i = 0; i < 100; i++) {
		cart[i].food_id = -1;
		cart[i].quantity = -1;
		cart[i].price = -1;
		cart[i].is_ala_cart = false;
		cart[i].sets_drinks_id = -1;
		cart[i].sets_snacks_id = -1;
	}

	register_membership();

	return 0;
}