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
void points(int points_to_spend, double& total_price);
int earn_points(double total_price);
void end_option(double total_price, int points_added);

#define NO_ERROR "none"

void payment_list(int& option_pay, double total_price, int sub_total) {

	ifstream read_file;
	string page_nav_err_msg = NO_ERROR;

	char option = 'a';

	string card_id;
	int member_points = 0, points_to_spend;
	double balance = 0.00;

	bool points_applied = false;

	while (option != 'p') {
		cout << "\033c";

		header();

		cout << setw(84) << left << setfill(' ') << "Item" << setw(10) << "Price" << setw(8) << "Quantity" << endl;

		for (size_t i = 0; i < cart_size; i++) {
			int numbering = i + 1;

			cout << left << numbering << (numbering >= 10 ? ". " : ".  ");

			if (!cart[i].is_ala_cart) {
				cout << setw(80) << menu_list_item[cart[i].food_id][0]
					+ " with " + menu_list_item[cart[i].sets_drinks_id][0]
					+ " & " + menu_list_item[cart[i].sets_snacks_id][0]
					+ " (Set meal)";
			}
			else {
				cout << setw(80) << menu_list_item[cart[i].food_id][0];
			}

			cout << left << "RM" << fixed << setprecision(2) << setw(8) << (double)cart[i].price << setw(8) << cart[i].quantity << endl;
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
						member_points = stoi(line);
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
		cout << "\nYour current membership point is " << member_points;

		cout << "\n\n----------Options----------" << "\n";
		cout << "Enter F to pay" << "\n";
		cout << "Enter K to apply membership points" << "\n";
		cout << "Enter P to previous page" << "\n\n";

		if (points_applied) {
			cout << points_to_spend << " Membership points is applied\n\n";
		}

		if (page_nav_err_msg != NO_ERROR)
			cout << page_nav_err_msg;

		cout << "Enter your input : ";
		cin >> option;

		while (!isalpha(option) || (isalpha(option) && (tolower(option) != 'f' && tolower(option) != 'p' && tolower(option) != 'k'))) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid Input! Try again.\n";
			cout << "Enter your input : ";
			cin >> option;
		}

		if (tolower(option) == 'k') {
			if (member_points >= 50) {
				cout << "\n**RM 1 spent = 1 Membership points**" << endl;
				cout << "**10 Membership points = RM0.10**" << endl;
				cout << "**You have to use at least 50 points**" << endl;
				cout << "How much point do you want to spend : ";
				cin >> points_to_spend;

				// TODO: fix infinite loop
				while (cin.fail() || points_to_spend < 50 || points_to_spend > member_points) {
					if (points_to_spend < 50) {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Sorry.You have to use at least 50 points.\n" << endl;
						cout << "How much point do you want to spend : ";
						cin >> points_to_spend;
					}
					else if (points_to_spend > member_points) {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "You have insufficient points to redeem.\n" << endl;
						cout << "How much point do you want to spend : ";
						cin >> points_to_spend;
					}
					else
						handle_invalid("How much point do you want to spend : ", points_to_spend);
				}

				points(points_to_spend, total_price);
				page_nav_err_msg = NO_ERROR;

			} else {
				page_nav_err_msg = "\nSorry.Your membership point is below 50 points.\n";
			}
		}

		if (tolower(option) == 'f') {

			int points_added = earn_points(total_price);

			balance_update(SUBTRACTION, total_price);

			cout << "\nPayment successful. Current balance: RM" << fixed << setprecision(2) << balance - total_price << "\n";
			cout << points_added << " Membership point has added." << "\n\n";

			this_thread::sleep_for(chrono::seconds(3));

			end_option(total_price, points_added);
		}
	}
}