#ifndef CART_VAR_H
#define CART_VAR_H

#include<string>

using namespace std;

extern struct Cart {
	int food_id;
	int quantity;
	int price;
	bool is_ala_cart;
	int sets_drinks_id;
	int sets_snacks_id;
};
extern struct Cart_Response {
	string message;
	bool is_success;
};
extern Cart cart[100];
extern int cart_size;

extern const double SERVICE_CHARGE;
extern const int PACKAGING_PRICE;

#endif