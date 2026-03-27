#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    BankAccount(string accName, int accNumber, double initialBalance) {
        name = accName;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposited: " << amount << " | New Balance: " << balance << "\n";
        } else {
            cout << "\nInvalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\nWithdrawn: " << amount << " | Remaining Balance: " << balance << "\n";
        } else {
            cout << "\nInsufficient Balance or Invalid Amount!\n";
        }
    }

    void displayAccount() {
        cout << "\n--- Account Details ---\n";
        cout << "Name: " << name << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice, accNo;
    string accName;
    double amount, initialBalance;

    do {
        cout << "\n===== Bank Management System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, accName);

            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Initial Balance: ";
            cin >> initialBalance;

            accounts.push_back(BankAccount(accName, accNo, initialBalance));
            cout << "\nAccount Created Successfully!\n";
            break;

        case 2: {
            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    acc.deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "\nAccount not found!\n";
            break;
        }

        case 3: {
            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    acc.withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "\nAccount not found!\n";
            break;
        }

        case 4: {
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    acc.displayAccount();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "\nAccount not found!\n";
            break;
        }

        case 5:
            cout << "\nThank you for using the Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}