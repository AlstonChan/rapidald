#include<iostream>
#include<string>

using namespace std;

void handle_invalid(string text, int& input) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Invalid input, Please try again.";
	cout << "\n" << text;
	cin >> input;
}