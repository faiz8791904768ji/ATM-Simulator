#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ATM {
private:
    double balance;
    vector<string> transactionHistory;
    const string pin = "1345";

    bool verifyPin() {
        string inputPin;
        cout << "Enter your pin: ";
        cin >> inputPin;
        return inputPin == pin;
    }

    void addTransaction(const string &transaction) {
        transactionHistory.push_back(transaction);
    }

public:
    ATM() : balance(0.0) {}

    void checkBalance() {
        cout << "Your current balance is Rs. " << balance << "\n";
    }

    void deposit() {
        double amount;
        cout << "Enter deposit amount: ";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Rs. " << amount << " deposited successfully\n";
            addTransaction("deposited: Rs. " + to_string(amount));
        } else {
            cout << "invalid amount\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter withdrawal amount: ";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Rs. " << amount << " withdrawn successfully\n";
            addTransaction("withdrew: Rs. " + to_string(amount));
        } else {
            cout << "Insufficient funds or invalid amount\n";
        }
    }

    void transfer(ATM &receiver) {
        double amount;
        cout << "Enter transfer amount: ";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            receiver.balance += amount;
            cout << "Rs. " << amount << " transferred successfully\n";
            addTransaction("transferred: Rs. " + to_string(amount));
            receiver.addTransaction("received: Rs. " + to_string(amount));
        } else {
         cout << "Insufficient funds or invalid amount\n";
        }
    }

    void showTransactionHistory() {
        cout << "Transaction history:\n";
        for (const auto &transaction : transactionHistory) {
            cout << transaction << "\n";
        }
    }

    void start() {
        if (!verifyPin()) {
            cout << "Incorrect pin\n";
            return;
        }

        int choice;
        do {
            cout<<"1. Check Balance\n";
            cout<<"2. Deposit\n";
            cout<<"3. Withdraw\n";
            cout << "4. Transfer\n";
           cout << "5. Transaction History\n";
           cout << "6. Exit\n";
           cout << "Choose an option: ";
           cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4: {
                    ATM receiver;
                    transfer(receiver);
                    break;
                }
                case 5:
                    showTransactionHistory();
                    break;
                case 6:
                    cout << "Goodbye\n";
                    break;
                default:
                    cout << "Invalid option\n";
                    break;
            }
        } while (choice != 6);
    }
};

int main() {
    ATM atm;
    atm.start();
     return 0;
}