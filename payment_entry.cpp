#include<iostream>
#include<fstream>

using namespace std;

void header(void);
void handle_invalid(string text, int& input);
void top_up(void);

#define NO_ERROR "none"

void payment_entry(int& option_pay, double total_price) {

	ifstream read_file;
	ofstream write_file;

	int option = 0;
	int points = 0;
	double balance = 0.00;
    string page_nav_err_msg = NO_ERROR;

	//write_file.open("member_details.txt", ios::app);
	//write_file << "Writing this to a file3.\n";
	//write_file << "Writing this to a file.4\n";
	//write_file.close();

	while (option != 3) {

		cout << "\033c";

		header();

		cout << "Your current balance is RM" << balance;
		cout << "\nTotal price for the order is RM" << total_price;
		cout << "\n\n1. Top up balance\n";
		cout << "2. Proceed to payment\n";
		cout << "3. Back to cart\n\n";

		if (page_nav_err_msg != NO_ERROR)
			cout << page_nav_err_msg;

		cout << "Enter your input : ";
		cin >> option;

		while (cin.fail() || option <= 0 || option > 3) {
			handle_invalid("Enter your input : ", option);
		}

		switch (option) {
		case 1:
			top_up();
			break;
		case 2:
			if (balance < total_price) {
				page_nav_err_msg = "You have insufficient balance\n";
			}
			break;
		}

	}
}