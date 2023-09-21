#include<iostream>
#include<string>

using namespace std;

void header(void);
void menu_main_list(int current_page);
void menu_food_selection(int option_num);

void menu_options_list(int current_page);

void cart_entry(void);
void option_input_validation(char accepted_option[], int size, string option, int current_page);

#define NO_ERROR "none"

void menu_options(int &current_page, string &option) {
	const int SIZE = 8;
	char accepted_option[SIZE] = { 'N', 'n', 'P', 'p', 'C', 'c', 'E', 'e' };
	static string page_nav_err_msg = NO_ERROR;

	menu_options_list(current_page);

	// Input Validation
	option_input_validation(accepted_option, SIZE, option, current_page);
	
	if (page_nav_err_msg != NO_ERROR) 
		cout << page_nav_err_msg;
	
	// If a listing number is selected and it is valid
	if (isdigit(option[0]) && (stoi(option) >= current_page * 9 + 1 && stoi(option) <= current_page * 9 + 9)) {
		int option_num = stoi(option);
		menu_food_selection(option_num);

		// The navigation to menu_food_selection has wiped all the
		// text outputed in menu_entry, so the following function
		// wiped the previous menu_food_selection output and ouput back
		// the menu_entry text.
		cout << "\033c";

		//header 
		header();

		// main menu
		menu_main_list(current_page);
		menu_options_list(current_page);
	}

	// Input
	cout << "Enter your input : ";
	cin >> option;

	switch ((option)[0]) {
		case 'N':
		case 'n':
			// If value is alphabet and wanted to go next page on the last page
			if (current_page < 1) {
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
		case 'c':
		case 'C':
			cart_entry();
			break;
		default:
			page_nav_err_msg = NO_ERROR;
	}
}

void menu_options_list(int current_page) {
	cout << "----------Options----------" << "\n";
	cout << "Enter " << current_page * 9 + 1 << " - " << current_page * 9 + 9 << " to select item" << "\n";
	if (current_page == 0) {
		cout << "Enter N to next page" << "\n";
	}
	if (current_page >= 1) {
		cout << "Enter P to previous page" << "\n";
	}
	cout << "Enter C to cart page" << "\n";
	cout << "Enter E to exit application" << "\n\n";
}