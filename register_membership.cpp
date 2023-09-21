#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<limits>
#include <ctime>

using namespace std;

void registerinfo();
void logininfo();

int main()
{
	char ans;
	//decoration
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	cout << setfill(' ');
	cout << setw(15) << ' ' << "Welcome to Rapidald!" << endl;
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	//Give customer choose is it member or not
	cout << "HAVE A MEMBER?" << endl;
	cout << "YES or NO (type Y or N)" << endl;
	cin >> ans;
	while (true)
	{
		if (ans == 'N' || ans == 'n')
		{
			registerinfo();
			return 0;
		}
		else if (ans == 'Y' || ans == 'y')
		{
			logininfo();
			return 0;
		}
		else
		{
			cout << "Invalid alphabet, please type again" << endl;
			cout << "YES or NO (type Y or N)" << endl;
			cin >> ans;

		}
	}
	return 0;
}
void registerinfo()
{
	string name, pnum;
	double cardnum, points, value;
	//decoration
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	cout << setfill(' ');
	cout << setw(18) << ' ' << "Registration" << endl;
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	//enter info and save it into file
	cout << "Please enter your name : ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << "Please enter your phone number : ";
	cin >> pnum;
	srand(time(NULL));
	cardnum = rand() % 100000 + 1;
	points = 0;
	value = 0;
	/*ofstream outfile;
	outfile.open("customerinfo.txt");
	outfile << name << pnum << cardnum;
	outfile.close();

	ifstream infile;
	infile.open("customerinfo.txt");

	if (!infile) {
		cout << "Error opening file"; return;
	}
	infile >> name >> pnum >> cardnum >> points >> value;*/
	cout << setfill(' ');
	cout << "\n\nWelcome, " << name << "!" << endl;
	cout << "Phone Number: " << right << setw(6) << ' ' << pnum << endl;
	cout << "Card  Number: " << right << setw(6) << ' ' << "ABC" << cardnum << endl;
	cout << "Top-up Value: " << right << setw(6) << ' ' << "RM " << fixed << setprecision(2) << value << endl;
	cout << "Membership Points: " << right << setw(2) << ' ' << fixed << setprecision(2) << points << endl;
}
void logininfo()
{
	string name, pnum;
	int cardnum;
	//decoration
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	cout << setfill(' ');
	cout << setw(20) << ' ' << "Login" << endl;
	cout << setfill('-');
	cout << setw(50) << ' ' << endl;
	//login by using phone number
	cout << "Pleas Enter Phone Number to Login : ";
	cin >> pnum;
}