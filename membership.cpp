#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void membership()
{
	double total_balance=100.0;
	int current_membership_point=100;
	int new_membership_point;
	double payment=12.0;
	int membership_point=0;
	double latest_payment;
	int membership_point_added;

	ifstream readFile("rapidald.txt");
	string readOut, id;
	int idFound = 0;

	//test
	cout << "Enter your id:";
	cin >> id;

	if (!readFile)
	{
		cout << "fail";
	}

	//find id and membership point
	while (getline(readFile, readOut))
	{

		if (readOut == id)
		{
			idFound = 1;
			readFile >> current_membership_point;
			if (current_membership_point >= 50)
			{
				while (membership_point < 50)
				{
					cout << "Membership point : " << current_membership_point << endl;
					cout << "How much point do you want to spend : ";
					cin >> membership_point;
					if (membership_point < 50)
						cout << "Sorry.You have to use at least 50 points." << endl;
					continue;
					if (membership_point >= 50)
						break;
				}
			}
			else
			{
				cout << "Sorry.Your membership point is below 50 points." << endl;
			}
		}
	}

	//test
	readFile.close();

	if (idFound == 0)
	{
		cout << "error" << endl;
	}

	latest_payment = (payment -( (membership_point) / static_cast<double>(100)));

	cout << "Your balance is : RM"
		<< double(total_balance - latest_payment) << endl;

	membership_point_added = int(latest_payment);
	new_membership_point = current_membership_point - membership_point + membership_point_added;

	cout << "Membership point will be added : " << membership_point_added << endl;
	cout << "Your membership point : " << new_membership_point << endl;
}