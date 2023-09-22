#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<limits>
#include <ctime>

using namespace std;
void menu_entry(void);
void header();
void register_membership();
void registerinfo();
void logininfo();
void handle_invalid(string text, int& input);

void register_membership()
{
	char ans;
	//decoration
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	cout << setfill(' ');
	cout << setw(15) << ' ' << "Welcome To Rapidald!" << endl;
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;

	//Give customer choose is it member or not
	cout << "HAVE A MEMBER? ('Y' for yes, 'N' for no)" << endl;
	cin >> ans;
	while(true)
	{
		if (ans == 'N' || ans == 'n')
		{
			cout << "\033c";
			registerinfo();
			break;
		}
		else if (ans == 'Y' || ans == 'y')
		{
			cout << "\033c";
			logininfo();
			break;
		}
		else
		{
			cout << "Invalid alphabet, please type again" << endl;
			cout << "YES or NO (type Y or N)" << endl;
			cin >> ans;

		}
	}
	return;
}
void registerinfo()
{
	string name, pnum;
	double points, value;
	int cardnum;
	//decoration
	cout << setfill(' ');
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	cout << setfill(' ');
	cout << setw(20) << ' ' << "Register" << endl;
	cout << setfill('-');
	
	cout << setw(50) << ' ' << endl;
	cout << "Please enter your name : ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << "Please enter your phone number : ";
	cin >> pnum;
	cout << "\033c";
	srand(time(NULL));
	cardnum = rand() % 100000 + 1;
	points = 0.00;
	value = 0.00;

	cout << setfill(' ');
	cout << "\n\nWelcome, " << name << "!" << endl;
	cout << "Phone Number: " << ' ' << pnum << endl;
	cout << "Card  Number: " << ' ' << "ABC" << cardnum << endl;
	cout << "Top-up Value: " << ' ' << "RM " << fixed << setprecision(2) << value << endl;
	cout << "Membership Points: " << ' ' << fixed << setprecision(2) << points << endl;
	cout << "Press 1 to proceed." << endl;
}
void logininfo() {
	string name, pnum, cardnum;
	double points, value;
	//decoration
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	cout << setfill(' ');
	cout << setw(20) << ' ' << "Login" << endl;
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	//login by using phone number
	cout << "Pleas Enter Phone Number to Login (Ex: 0105198931)"<< endl;
	cin >> pnum;
	cout << setfill(' ');
	cout << "Welcome, " << name << "!" << endl;
	cout << "Phone Number: " << pnum << endl;
	cout << "Card  Number: " << "ABC" << cardnum << endl;
	cout << "Top-up Value: " << "RM " << fixed << setprecision(2) << "value" << endl;
	cout << "Membership Points: " << fixed << setprecision(2) << "points" << endl;
}