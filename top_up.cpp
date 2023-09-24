#include<iostream>
#include<iomanip>
#include <chrono>
#include <thread>

#include "menu_var.h"

using namespace std;

void header(void);
void handle_invalid(string text, int& input);
void termination(void);
void balance_update(OPERATIONS operation, double value);

void top_up() {

    double customer_balance = 0.0, customer_prev_balance = 0.0;
    double amount = 0.0;
    int num;

    cout << "\033c";

    header();

    cout << "Select top up amount value: \n1. RM5.00\n2. RM10.00\n3. RM30.00\n4. RM50.00\n";
    cout << "-------------------" << endl;
    cout << "Enter your choice: ";

    int top_up_amount;
    cin >> top_up_amount;

    while (cin.fail() || top_up_amount <= 0 || top_up_amount > 4) {
        handle_invalid("Enter your choice : ", top_up_amount);
    }

    switch (top_up_amount) {
        case 1:
            amount = 5.0;
            break;
        case 2:
            amount = 10.0;
            break;
        case 3:
            amount = 30.0;
            break;
        case 4:
            amount = 50.0;
            break;
    }

    switch (static_cast<int>(amount)) {
        case 5:
        case 10:
        case 30:
        case 50:
            customer_balance += amount - 0.5;
            break;
        default:
            cout << "\nInvalid top up amount." << endl << endl;
            cout << "Current balance: RM" << fixed << setprecision(2) << customer_balance << "\n\n";
            break;
    }

    balance_update(ADDITION, customer_balance);

    cout << "\nTop up successful. Current balance: RM" << fixed << setprecision(2) << customer_prev_balance + customer_balance << "\n\n";

    this_thread::sleep_for(chrono::seconds(3));
}