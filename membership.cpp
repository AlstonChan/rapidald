#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>


using namespace std;

void membership()
{
	double total_balance = 100.0;
	int current_membership_point=100;
	int new_membership_point;
	double payment = 12.0;
	int membership_point = 0;
	double latest_payment;
	int membership_point_added;
	char option_using_membership;

	cout << "Do you want to use membership point." << endl;
	cout << "Yes or No ( Type Y or N) : ";
	cin >> option_using_membership;

	while(option_using_membership == 'Y' || option_using_membership == 'y')
	{
		
		if (current_membership_point >= 50)
		{
			while (membership_point < 50)
			{
				cout << setfill('-') << setw(50) << ' ' << endl;
				cout << setfill(' ');
				cout << "\nPayment : RM" << payment << endl;
				cout << "Your balance : RM" << total_balance << endl;
				cout << "Membership point : " << current_membership_point << endl;
				cout << "**10 Membership points = RM0.10**" << endl;
				cout << "**You have to use at least 50 points**" << endl;
				cout << "How much point do you want to spend : ";
				cin >> membership_point;
				if (membership_point < 50)
					cout << "Sorry.You have to use at least 50 points.\n" << endl;
				
				if (total_balance < payment - double(membership_point / 100))
					cout << "Your balance is not enough to cover your payment. Please try again." << endl;
				
			}
		}
		else
		{
			cout << "Sorry.Your membership point is below 50 points.\n" << endl;
		}
		break;
	}
	while (option_using_membership == 'N' || option_using_membership == 'n')
	{
		cout << " " << endl;
		break;
	}
	while(option_using_membership!='n'&& option_using_membership != 'N' && option_using_membership != 'y' && option_using_membership != 'y')
	{
		cout << "This is not the option.Please try again." << endl;
		break;
	}


	latest_payment = (payment - ((membership_point) / static_cast<double>(100)));

	cout << setfill('-') << setw(50) << ' ' << endl;
	cout << setfill(' ');
	cout << "\nYour balance : RM"
		<< double(total_balance - latest_payment) << endl;

	membership_point_added = int(latest_payment);
	new_membership_point = current_membership_point - membership_point + membership_point_added;


	cout << "\nMembership point will be added : " << membership_point_added << endl;
	cout << "Your membership point : " << new_membership_point << endl;

	cout << setfill('-') << setw(50) << ' ' << endl;
	cout << setfill(' ');

	cout << "Thank you for having our services.";

}