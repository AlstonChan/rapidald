#include<iostream>
#include<string>
#include<iomanip>
#include<limits>

using namespace std;

void register_membership() {
	//Give customer choose is it member or not
	char ans;
	cout << "HAVE A MEMBER?" << endl;
	cout << "YES or NO (type Y or N)" << endl;
	cin >> ans;

	//After answer redircting to which page
	int pnum;
	string name;
	while (true)
	{
		if (ans == 'Y' || ans == 'y')
		{
			cout << "Please enter your phone number: +60";
			cin >> pnum;
			break;
		}
		else if (ans == 'N' || ans == 'n')
		{
			cout << "Please enter your name: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			cout << "Please enter your phone number: +60";
			cin >> pnum;
			break;
		}
		else
		{
			cout << "Please enter again 'Y' or 'N'" << endl;
			cin >> ans;
		}
	}
	int points, value;
	string cardnum;
	cout << setfill('-') << setw(50) << ' ' << endl;
	cout << setfill(' ');
	cout << "Member's Name" << setw(16) << ": " << name << endl;
	cout << "Contact Number" << setw(18) << ": +60" << pnum << endl;
	cout << "Membership card number" << setw(7) << ": " << cardnum << endl;
	cout << "Top-up Value" << setw(17) << ": " << "value" << endl;
	cout << "Membership Points" << setw(12) << ": " << "points" << endl;
}