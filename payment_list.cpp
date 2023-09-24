#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <chrono>
#include <thread>

#include "menu_var.h"
#include "cart_var.h"

using namespace std;

void header(void);
void handle_invalid(string text, int& input);
void top_up(void);
void balance_update(OPERATIONS operation, double value);

void payment_list(int& option_pay, double total_price, int sub_total) {

	ifstream read_file;

	char option;

	string card_id;
	int points = 0;
	double balance = 0.00;

	cout << "\033c";

	header();

	cout << setw(84) << left << setfill(' ') << "Item" << setw(10) << "Price" << setw(8) << "Quantity" << endl;

	for (size_t i = 0; i < cart_size; i++) {
		int numbering = i + 1;

		cout << left << numbering << (numbering >= 10 ? ". " : ".  ") ;

		if (!cart[i].is_ala_cart) {
			cout << setw(80) << menu_list_item[cart[i].food_id][0]
				+ " with " + menu_list_item[cart[i].sets_drinks_id][0] 
				+ " & " + menu_list_item[cart[i].sets_snacks_id][0]
				+ " (Set meal)";
		} else {
			cout << setw(80) << menu_list_item[cart[i].food_id][0];
		}

		cout << left << "RM" << fixed << setprecision(2) << setw(8) << (double) cart[i].price << setw(8) << cart[i].quantity << endl;
	}

	cout << "\n\n";
	cout << setw(16) << setfill(' ') << left << "Sub Total" << " : " << "RM" << fixed << setprecision(2) << sub_total << endl;

	cout << setw(16) << left << (option_pay == 1 ? "Service Charge" : "Packaging Price") << " : " 
		<< (option_pay == 1 ? "(%) " : "RM") << fixed << setprecision(2)
		<< (option_pay == 1 ? SERVICE_CHARGE : (double)PACKAGING_PRICE) << endl;
	cout << setw(16) << left << "Total Price" << " : " << "RM" << fixed << setprecision(2)
		<< total_price << endl;

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
					is_matching_member_line_count++;
					break;
				case 3:
					card_id = line;
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

			if (is_matching_member_line_count == 6)
				continue;
		}
		read_file.close();
	}

	cout << "\nYour Card Number is " << card_id;
	cout << "\nYour current balance is RM" << fixed << setprecision(2) << balance;
	cout << "\nYour current membership point is " << points;

	cout << "\n\n----------Options----------" << "\n";
	cout << "Enter F to pay" << "\n";
	cout << "Enter P to previous page" << "\n\n";

	cout << "Enter your input : ";
	cin >> option;

	while (!isalpha(option) || (isalpha(option) && (tolower(option) != 'f' && tolower(option) != 'p'))) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid Input! Try again.\n";
		cout << "Enter your input : ";
		cin >> option;
	}

	if (tolower(option) == 'f') 
		balance_update(SUBTRACTION, total_price);

	cout << "\nPayment successful. Current balance: RM" << fixed << setprecision(2) << balance - total_price << "\n\n";

	this_thread::sleep_for(chrono::seconds(2));
}