#include <iostream>
#include <vector>
#include <string>

using namespace std;

// كلاس يمثل الحساب البنكي
class BankAccount {
public:
    int accountNumber;
    string accountHolder;
    double balance;

    BankAccount(int accNum, string name, double initialDeposit) {
        accountNumber = accNum;
        accountHolder = name;
        balance = initialDeposit;
    }
};

// كلاس إدارة البنك
class Bank {
private:
    vector<BankAccount> accounts;

public:
    // إنشاء حساب جديد
    void createAccount() {
        int accNum;
        string name;
        double initialDeposit;

        cout << "Enter Account Number: ";
        cin >> accNum;
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, name);
        cout << "Enter Initial Deposit Amount: $";
        cin >> initialDeposit;

        accounts.push_back(BankAccount(accNum, name, initialDeposit));
        cout << "Account Created Successfully!\n";
    }

    // إيداع أموال
    void deposit() {
        int accNum;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNum;

        for (auto& acc : accounts) {
            if (acc.accountNumber == accNum) {
                cout << "Enter Amount to Deposit: $";
                cin >> amount;
                if (amount > 0) {
                    acc.balance += amount;
                    cout << "Deposited successfully! New Balance: $" << acc.balance << "\n";
                } else {
                    cout << "Invalid amount!\n";
                }
                return;
            }
        }
        cout << "Account not found.\n";
    }

    // سحب أموال
    void withdraw() {
        int accNum;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNum;

        for (auto& acc : accounts) {
            if (acc.accountNumber == accNum) {
                cout << "Enter Amount to Withdraw: $";
                cin >> amount;
                if (amount > acc.balance) {
                    cout << "Insufficient balance! Your current balance is: $" << acc.balance << "\n";
                } else if (amount > 0) {
                    acc.balance -= amount;
                    cout << "Withdrawn successfully! New Balance: $" << acc.balance << "\n";
                } else {
                    cout << "Invalid amount!\n";
                }
                return;
            }
        }
        cout << "Account not found.\n";
    }

    // عرض تفاصيل الحساب
    void checkBalance() {
        int accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        for (const auto& acc : accounts) {
            if (acc.accountNumber == accNum) {
                cout << "\n--- Account Details ---\n";
                cout << "Holder: " << acc.accountHolder << "\n";
                cout << "Account Number: " << acc.accountNumber << "\n";
                cout << "Current Balance: $" << acc.balance << "\n";
                return;
            }
        }
        cout << "Account not found.\n";
    }
};

int main() {
    Bank myBank;
    int choice;

    do {
        cout << "\n=== Bank Management System ===\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance / Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: myBank.createAccount(); break;
            case 2: myBank.deposit(); break;
            case 3: myBank.withdraw(); break;
            case 4: myBank.checkBalance(); break;
            case 5: cout << "Thank you for using our Banking System!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
