#include<iostream>
#include<fstream>
#include<string>

#include "menu_var.h"

using namespace std;

void balance_update(OPERATIONS operation, double value) {

	ifstream read_file;
	ofstream write_file;

	double original_value;

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
					original_value = stod(line);
					line = to_string(operation == ADDITION ? (value + original_value) : (original_value - value));
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