#include<iostream>
#include<string>

using namespace std;

void option_input_validation(char accepted_option[], int size ,string option, int current_page) {
	// If value is digit and did not match the current page listing number
	if (isdigit(option[0]) && (stoi(option) < current_page * 9 + 1 || stoi(option) > current_page * 9 + 9))
		cout << "Number " << stoi(option) << " is not an option. Try again.\n";

	// If value is alphabet and did not match the options character (N, P, C, E, F)
	if (isalpha(option[0])) {
		bool has_matched = false;

		for (size_t i = 0; i < size; i++) {
			if (accepted_option[i] == option[0]) {
				has_matched = true;
			}
		}

		if (!has_matched) {
			cout << "Character " << (option)[0] << " is not an option. Try again.\n";
		}
	}
}