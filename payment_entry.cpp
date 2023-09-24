#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

#include "menu_var.h"

using namespace std;

void header(void);
void handle_invalid(string text, int& input);
void top_up(void);

void payment_list(int& option_pay, double total_price, int sub_total);

#define NO_ERROR "none"

void payment_entry(int& option_pay, double total_price, int sub_total) {

	ifstream read_file;

	int option = 0;

	int points = 0;
	double balance = 0.00;
    string page_nav_err_msg = NO_ERROR;

	while (option != 3) {

		cout << "\033c";

		header();

		read_file.open("member_details.txt");

		if (read_file.is_open()) {
			string line;
			bool is_matching_member = false;
			int is_matching_member_line_count = 1;

			while (getline(read_file, line)) {
				if (line == registered_user_phone_num) {
					is_matching_member = true;
				}

				if (is_matching_member) {
					switch (is_matching_member_line_count) {
					case 1:
					case 2:
					case 3:
						is_matching_member_line_count++;
						break;
					case 4:
						balance = stod(line);
						is_matching_member_line_count++;
						break;
					case 5:
						points = stoi(line);
						is_matching_member_line_count++;
						break;
					}
				}
			}
			read_file.close();
		}

		cout << "Your current balance is RM" << fixed << setprecision(2) << balance;
		cout << "\nYour current membership point is " << points;
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
			else if (balance >= total_price) {
				payment_list(option_pay, total_price, sub_total);
			}
			break;
		}

	}
}