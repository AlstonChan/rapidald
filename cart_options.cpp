#include<iostream>
#include<iomanip>
#include<string>

#include "cart_var.h"

using namespace std;

void header(void);
void cart_options_list(int current_page);
void cart_item_selection(int option_num);
void cart_main_list(int current_page);
void handle_invalid(string text, int& input);

void option_input_validation(char accepted_option[], int size ,string option, int current_page);

void payment_entry(int& option_pay, double total_price);

#define NO_ERROR "none"

void cart_options(int &current_page, string &option, int &dining_option) {
	const double SERVICE_CHARGE = 0.1;
	const int PACKAGING_PRICE = 2;
	const int SIZE = 10;
	char accepted_option[SIZE] = { 'N', 'n', 'P', 'p', 'M', 'm', 'F', 'f' ,'E', 'e'};
	static string page_nav_err_msg = NO_ERROR;

	// Option Listing
	cart_options_list(current_page);

	// Input Validation
	option_input_validation(accepted_option, SIZE, option, current_page);

	if (isdigit(option[0]) && stoi(option) <= ((current_page + 1) * 9) && !(cart_size > stoi(option)))
		cout << "Number " << option << " is not an option. Try again.\n";

	if (page_nav_err_msg != NO_ERROR)
		cout << page_nav_err_msg;

	// If a listing number is selected and it is valid
	if (
		isdigit(option[0]) && 
		(
			stoi(option) >= current_page * 9 + 1 && 
			stoi(option) <= current_page * 9 + 9
		) && 
		cart[stoi(option) - 1].food_id != -1
		) {
		int option_num = stoi(option);
		cart_item_selection(option_num);

		// The navigation to cart_item_selection has wiped all the
		// text outputted in cart_entry, so the following function
		// wiped the previous cart_item_selection output and ouput back
		// the cart_entry text.
		cout << "\033c";

		//header 
		header();

		// show cart
		cart_main_list(current_page);
		cart_options_list(current_page);
	}

	// Input
	cout << "Enter your input : ";
	cin >> option;

	switch ((option)[0]) {
		case 'N':
		case 'n':
			// If value is alphabet and wanted to go next page on the last page
			if (cart_size <= 9) {
				page_nav_err_msg = "Character ";
				page_nav_err_msg += (option)[0];
				page_nav_err_msg += " is not an option. Try again.\n";
			} else if (cart_size > (current_page + 1) * 9) {
				++current_page;
				page_nav_err_msg = NO_ERROR;
			} else
				page_nav_err_msg = "There is the last page. Try again.\n";
			break;

		case 'P':
		case 'p':
			// If value is alphabet and wanted to go back one page on the first page
			if (current_page >= 1) {
				--current_page;
				page_nav_err_msg = NO_ERROR;
			} else
				page_nav_err_msg = "There is no previous page. Try again.\n";
			break;

		case 'F':
		case 'f': {

			if (cart_size != 0) {
				cout << "\nWould you like to Dine in or Take Away?\n";
				cout << "1. Dine in\n";
				cout << "2. Take Away\n\n";
				cout << "Enter your input (1 or 2) : ";
			
				cin >> dining_option;

				while (cin.fail() || (dining_option <= 0 || dining_option > 2)) {
					handle_invalid("Enter your input (1 or 2) : ", dining_option);
				}

				double total_price = 0;
				for (size_t i = 0; i < cart_size; i++) {
					total_price += cart[i].price;
				}

				cout << "\nSubtotal : RM" << total_price;

				if (dining_option == 1) {
					double service_charge = total_price * SERVICE_CHARGE;
					cout << "\n10% Service Charge : RM" << service_charge;
					total_price = service_charge + total_price;

				} else if (dining_option == 2) {
					total_price += PACKAGING_PRICE;
					cout << "\nPackaging price : RM" << PACKAGING_PRICE;
				}

				cout << "\nTotal Price : RM" << fixed << setprecision(2) << total_price;

				int option_pay;

				cout << "\n\n1. Proceed to payment\n";
				cout << "2. Back to Cart\n";
				cout << "Enter your Option (1 or 2) : ";
				cin >> option_pay;

				while (cin.fail() || (option_pay <= 0 || option_pay > 2)) {
					handle_invalid("Enter your Option (1 or 2) : ", dining_option);
				}

				if (option_pay == 1) {
					payment_entry(option_pay, total_price);
				}
			}
			else {
				page_nav_err_msg = "There is nothing in the cart. Try again.\n";
			}

		}
		break;

		default:
			page_nav_err_msg = NO_ERROR;
	}
}

void cart_options_list(int current_page) {
	int current_cart_numbering = cart_size > 9 ? 9 : cart_size;

	// Options Selection List
	cout << "----------Options----------" << "\n";
	if (cart_size != 0) {
		if (cart_size == 1) {
			cout << "Enter 1 to select item" << "\n";
		}
		else cout << "Enter " << current_page * 9 + 1 << " - " << current_page * 9 + current_cart_numbering << " to select item" << "\n";
	}
	if (cart_size > 9 && cart_size > (current_page + 1) * 9)
		cout << "Enter N to next page" << "\n";
	if (current_page >= 1)
		cout << "Enter P to previous page" << "\n";
	cout << "Enter M to menu page" << "\n";
	if (cart_size != 0)
		cout << "Enter F to checkout" << "\n";
	cout << "Enter E to exit application" << "\n\n";
	// Options Selection List End
}