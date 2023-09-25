#include<iostream>
#include<iomanip>
#include<string>
#include<limits>
#include<ctime>
#include<fstream>

#include "menu_var.h"

using namespace std;

void register_info();
void login_info();
void phone_num_validation(bool is_register, string text, string& phone_num);
void register_options(char& option);

void termination(void);
void menu_entry(void);
void header();
void intro(void);
void handle_invalid(string text, int& input);

string registered_user_phone_num;

void register_membership() {
	char has_membership; // Y for yes, N for no

	intro();

	//Give customer choose is it member or not
	cout << "\nDo you have a membership? (Y for yes, N for no) : ";
	cin >> has_membership;

	while (!isalpha(has_membership) || (isalpha(has_membership) && (tolower(has_membership) != 'y' && tolower(has_membership) != 'n') ) ) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid input! Try again.\n";
		cout << "Do you have a membership? (Y for yes, N for no) : ";
		cin >> has_membership;
	}

	switch (tolower(has_membership)) {
	case 'y':
		login_info();
		break;
	case 'n':
		register_info();
		break;
	}
}

void register_info() {

	ofstream write_file;

	string name, phone_num, card_id;
	char option;
	int card_num, card_head;
	
	cout << "Please enter your name : ";

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);

	cout << "Please enter your phone number (Ex: 012-3456789) : ";
	cin >> phone_num;

	phone_num_validation(true, "Please enter your phone number (Ex: 012-3456789) : ", phone_num);

	srand(time(NULL));

	card_head = stoi(to_string((rand() % 9 + 1)) + "00000");
	card_num = card_head + rand() % 100000;
	card_id = "ABC" + to_string(card_num);

	cout << "\nWelcome, " << name << "!" << endl;
	cout << "Phone Number : " << phone_num << endl;
	cout << "Card Number : " << card_id << endl;
	cout << "Card Balance : " << "RM " << fixed << setprecision(2) << 0.00 << endl;
	cout << "Membership Points: " << 0 << endl << endl;

	registered_user_phone_num = phone_num;

	cout << "Your account have been registered and you are now logged in.";

	write_file.open("member_details.txt", ios::app);
	write_file << phone_num << '\n';
	write_file << name << '\n';
	write_file << card_id << '\n';
	write_file << '0' << '\n';
	write_file << '0' << '\n';
	write_file.close();

	register_options(option);
}

void login_info() {

	ifstream read_file;

	string name, phone_num, card_id;
	char option;
	double balance = 0.0;
	int points = 0;

	cout << "Please enter your phone number to login (Ex: 012-3456789) : ";
	cin >> phone_num;

	phone_num_validation(false, "Please enter your phone number to login (Ex: 012-3456789) : ", phone_num);

	read_file.open("member_details.txt");

	if (read_file.is_open()) {
		string line;
		bool is_matching_member = false;
		int is_matching_member_line_count = 1;

		while (getline(read_file, line)) {
			if (line == phone_num) {
				is_matching_member = true;
			}

			if (is_matching_member) {
				switch (is_matching_member_line_count) {
				case 1:
					phone_num = line;
					is_matching_member_line_count++;
					break;				
				case 2:
					name = line;
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
		}
		read_file.close();

		registered_user_phone_num = phone_num;

		cout << "\nWelcome, " << name << "!" << endl;
		cout << "Phone Number: " << phone_num << endl;
		cout << "Card Number: " << card_id << endl;
		cout << "Card Balance: " << "RM " << fixed << setprecision(2) << balance << endl;
		cout << "Membership Points: " << points << endl << endl;

		cout << "You are now logged in.";

	} else cout << "\nNo registered user found";

	register_options(option);
}

void phone_num_validation(bool is_register, string text, string& phone_num) {

	ifstream read_file;

	bool has_invalid_char = false;
	bool has_matching_member = false;

	read_file.open("member_details.txt");

	if (read_file.is_open()) {
		string line;

		while (getline(read_file, line)) {
			if (line == phone_num) {
				has_matching_member = true;
			}
		}
		read_file.close();
	}

	if (phone_num.length() == 11 || phone_num.length() == 12)
		for (size_t i = 0; i < phone_num.length(); i++) {
			if (!isdigit(phone_num[i])) {
				if (i == 3 && phone_num[i] != '-') {
					has_invalid_char = true;
				} else if (i != 3)
					has_invalid_char = true;
			}
		}
	else
		has_invalid_char = true;

	if (!is_register && !has_invalid_char && !has_matching_member) {
		cout << "\nThis phone number is not registered! Try another.\n";
		cout << text;
		cin >> phone_num;

		phone_num_validation(is_register, text, phone_num);
	}

	if (has_invalid_char) {
		cout << "\nInvalid phone number! Try again.\n";
		cout << text;
		cin >> phone_num;

		phone_num_validation(is_register, text, phone_num);
	}

	if (is_register && has_matching_member) {
		cout << "\nPhone number has been taken! Try another.\n";
		cout << text;
		cin >> phone_num;

		phone_num_validation(is_register, text, phone_num);
	}
}

void register_options(char& option) {
	cout << "\n\n----------Options----------" << "\n";
	cout << "Enter M to proceed" << "\n";
	cout << "Enter E to exit application" << "\n\n";

	cout << "Enter your input : ";
	cin >> option;

	while (!isalpha(option) || (isalpha(option) && (tolower(option) != 'm' && tolower(option) != 'e'))) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid input! Try again.\n";
		cout << "Enter your input : ";
		cin >> option;
	}

	switch (tolower(option)) {
	case 'm':
		menu_entry();
		break;
	case 'e':
		termination();
		break;
	}
}