#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <chrono>
#include <thread>

#include "menu_var.h"

using namespace std;

void termination(void);

void refund(double total_price, int points_added) {

	ifstream read_file;
	ofstream write_file;

	double balance = 0.0;
	int points = 0;

	const string filename = "member_details.txt";
	read_file.open(filename);
	write_file.open("member_details_temp.txt");

	if (!read_file || !write_file) {
		cout << "Error opening files." << std::endl;
	}

	if (read_file.is_open() && write_file.is_open()) {
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
					line = to_string(balance + total_price);
					is_matching_member_line_count++;
					break;
				case 5:
					points = stoi(line);
					line = to_string(points - points_added);
					is_matching_member_line_count++;
					break;
				}
			}

			write_file << line << '\n';
		}
	}

	read_file.close();
	write_file.close();

	if (remove(filename.c_str()) != 0) {
		cout << "Error deleting the original file." << endl;
	}

	if (rename("member_details_temp.txt", filename.c_str()) != 0) {
		cout << "Error renaming the temporary file." << endl;
	}

	cout << "\nPayment successful. Current balance: RM" << fixed << setprecision(2) << balance + total_price << "\n";
	cout << points_added << " Membership point has been deducted." << "\n\n";

	this_thread::sleep_for(chrono::seconds(3));

	termination();
}