#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<math.h>

#include "menu_var.h"

using namespace std;

void points(int points_to_spend, double& total_price)
{
	int membership_point_added = 0;

	double discount;

	discount = points_to_spend / 100.0;
	total_price = total_price - discount;

	ifstream read_file;
	ofstream write_file;

	int points;
	int points_after_deducted = 0;

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
				case 4:
					is_matching_member_line_count++;
					break;
				case 5:
					points = stoi(line);
					points_after_deducted = points - points_to_spend;
					line = to_string(points_after_deducted);
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
}

int earn_points(double total_price) {

	ifstream read_file;
	ofstream write_file;

	int points;
	int points_after_added = 0;

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
				case 4:
					is_matching_member_line_count++;
					break;
				case 5:
					points = stoi(line);
					points_after_added = points + static_cast<int>(floor(total_price));
					line = to_string(points_after_added);
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

	return static_cast<int>(floor(total_price));
}