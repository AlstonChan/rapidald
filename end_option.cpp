#include<iostream>

using namespace std;

void handle_invalid(string text, int& input);
void termination(void);
void refund(double total_price, int points_added);

void end_option(double total_price, int points_added) {
	int last_option;

	cout << "Order has been made, which option do you wish to proceed next.\n";
	cout << "1. Cancel the last purchase.\n";
	cout << "2. Exit application.\n\n";

	cout << "Enter your option";
	cin >> last_option;

	while (cin.fail() || last_option <= 0 || last_option > 2) {
		handle_invalid("Enter your option : ", last_option);
	}

	switch (last_option) {
	case 1:
		refund(total_price, points_added);
		break;
	case 2:
		termination();
		break;
	}
}