#include<iostream>
#include<string>

using namespace std;

void option_input_validation(char accepted_option[], string option, int current_page) {
	// If value is digit and did not match the current page listing number
	if (isdigit(option[0]) && (stoi(option) < current_page * 9 + 1 || stoi(option) > current_page * 9 + 9))
		cout << "Number " << stoi(option) << " is not an option. Try again.\n";

	// If value is alphabet and did not match the options character (N, P, C, E)
	char* matched_charPtr = find(accepted_option, accepted_option + sizeof(accepted_option), (option)[0]);
	if (isalpha(option[0]) && matched_charPtr == accepted_option + sizeof(accepted_option))
		cout << "Character " << (option)[0] << " is not an option. Try again.\n";
}