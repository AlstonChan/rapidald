#include<iostream>
#include<string>

#include "cart_var.h"

using namespace std;

void header(void);
void cart_options_list(int current_page);
void cart_item_selection(int option_num);
void cart_main_list(int current_page);

void option_input_validation(char accepted_option[], string option, int current_page);

#define NO_ERROR "none"

void cart_options(int &current_page, string &option) {
	char accepted_option[] = { 'N', 'n', 'P', 'p', 'M', 'm', 'E', 'e' };
	static string page_nav_err_msg = NO_ERROR;

	// Option Listing
	cart_options_list(current_page);

	// Input Validation
	option_input_validation(accepted_option, option, current_page);

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
		// text outputed in cart_entry, so the following function
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
				page_nav_err_msg = "Character " + (option)[0];
				page_nav_err_msg += " is not an option. Try again.\n";
			} else if (current_page < 1) {
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
	if (cart_size > 9)
		cout << "Enter N to next page" << "\n";
	if (current_page >= 1)
		cout << "Enter P to previous page" << "\n";
	cout << "Enter M to menu page" << "\n";
	cout << "Enter E to exit application" << "\n\n";
	// Options Selection List End
}