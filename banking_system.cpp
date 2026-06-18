#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string customerName;
    int accountNumber;
    double balance;
    vector<string> transactions;

public:
    void createAccount() {
        cout << "\nEnter Customer Name: ";
        cin.ignore();
        getline(cin, customerName);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Deposit: ";
        cin >> balance;

        transactions.push_back("Account Created: +" + to_string(balance));
    }

    void deposit() {
        double amount;

        cout << "Enter Deposit Amount: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            transactions.push_back("Deposit: +" + to_string(amount));
            cout << "Deposit Successful!\n";
        } else {
            cout << "Invalid Amount!\n";
        }
    }

    void withdraw() {
        double amount;

        cout << "Enter Withdrawal Amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid Amount!\n";
        }
        else if (amount > balance) {
            cout << "Insufficient Balance!\n";
        }
        else {
            balance -= amount;
            transactions.push_back("Withdrawal: -" + to_string(amount));
            cout << "Withdrawal Successful!\n";
        }
    }

    void displayAccount() {
        cout << "\n===== ACCOUNT DETAILS =====\n";
        cout << "Customer Name : " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance       : Rs. "
             << fixed << setprecision(2)
             << balance << endl;
    }

    void showTransactions() {
        cout << "\n===== TRANSACTION HISTORY =====\n";

        if (transactions.empty()) {
            cout << "No Transactions Available.\n";
            return;
        }

        for (int i = 0; i < transactions.size(); i++) {
            cout << i + 1 << ". "
                 << transactions[i] << endl;
        }
    }
};

int main() {

    BankAccount account;

    account.createAccount();

    int choice;

    do {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View Account Details\n";
        cout << "4. Transaction History\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                account.deposit();
                break;

            case 2:
                account.withdraw();
                break;

            case 3:
                account.displayAccount();
                break;

            case 4:
                account.showTransactions();
                break;

            case 5:
                cout << "\nThank You For Using Banking System!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}