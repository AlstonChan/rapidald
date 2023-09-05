#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

void top_up() {
    double customerBalance = 0.0;
    double amount;
    int num;

    do {
        cout << "1. Top up amount.\n2. Balance of top up amount.\n3. Top up finished.\n";
        cout << "Enter your choice: ";
        cin >> num;

        switch (num) {
            case 1: 
                cout << "\033c";

                cout << "Select top up amount value: \n1. RM5.00\n2. RM10.00\n3. RM30.00\n4. RM50.00\n";
                cout << "Enter your choice: ";

                int topupAmount;
                cin >> topupAmount;

                switch (topupAmount) {
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
                    default:
                        cout << "Invalid top up amount.\n";
                        continue;
                    }

                switch (static_cast<int>(amount)) {
                    case 5:
                    case 10:
                    case 30:
                    case 50:
                        customerBalance += amount - 0.5;
                        cout << "Top up successful. Current balance: RM" << fixed << setprecision(2) << customerBalance << endl;
                        break;
                    default:
                        cout << "Invalid top up amount." << endl;
                        cout << "Current balance: RM" << fixed << setprecision(2) << customerBalance << endl;
                        break;
                    }
             break;
            
        case 2:
            cout << "-------------------";
            cout << "Current balance: RM" << fixed << setprecision(2) << customerBalance << endl;
            cout << "-------------------";
            break;

        case 3:
            cout << "Thank you for your top up. Enjoy your meal.\n";
            break;

        default:
            // This clears the terminal for clarity sake
            // refer to https://stackoverflow.com/questions/47503734/what-does-printf-033c-mean
            cout << "\033c";
        }
    } while (num != 3);
}