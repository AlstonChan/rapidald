#include<iostream>
#include<string>

using namespace std;

void food_selection(int option_num);
void menu_show_cart(void);

#define NO_ERROR "none"

void options_section(int &current_page, string &option)
{
	char accepted_option[] = { 'N', 'n', 'P', 'p', 'C', 'c', 'E', 'e' };
	static string page_nav_err_msg = NO_ERROR;

	// Options Selection List
	cout << "----------Options----------" << "\n";
	cout << "Enter " << current_page * 9 + 1 << " - " << current_page * 9 + 9 << " to select item" << "\n";
	cout << "Enter N to next page" << "\n";

	if (current_page >= 1) {
		cout << "Enter P to previous page" << "\n";
	}

	cout << "Enter C to cart page" << "\n";
	cout << "Enter E to exit application" << "\n" << "\n";
	// Options Selection List End

	// Input Validation
	// If value is digit and did not match the current page listing number
	if (isdigit(option[0]) && (stoi(option) < current_page * 9 + 1 || stoi(option) > current_page * 9 + 9)) 
		cout << "Number " << stoi(option) << " is not an option. Try again.\n";
	

	// If value is alphabet and did not match the options character (N, P, C, E)
	char* matched_charPtr = find(begin(accepted_option), end(accepted_option), (option)[0]);
	if (isalpha(option[0]) && matched_charPtr == end(accepted_option)) 
		cout << "Character " << (option)[0] << " is not an option. Try again.\n";
	

	if (page_nav_err_msg != NO_ERROR) 
		cout << page_nav_err_msg;
	
	// If a listing number is selected and it is valid
	if (isdigit(option[0]) && (stoi(option) >= current_page * 9 + 1 && stoi(option) <= current_page * 9 + 9)) {
		int option_num = stoi(option);
		food_selection(option_num);
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
		menu_show_cart();
		break;
	}
}