#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

#include "menu_var.h"

using namespace std;

void header() {

	ifstream read_file;

	string name;

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
					is_matching_member_line_count++;
					break;
				case 2:
					name = line;
					is_matching_member_line_count++;
					break;
				}
			}

			if (is_matching_member_line_count == 3)
				continue;
		}
		read_file.close();
	}

	cout << left << setw(40) << setfill(' ') << "rapidald" << name << "\n\n";
}