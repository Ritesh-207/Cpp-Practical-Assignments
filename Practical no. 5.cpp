#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAudit;

class BankAccount {
private:
    int accountNumber;
    string customerName;
    double balance;

    static int totalAccounts;

public:
    // Constructor using this pointer
    BankAccount(int accountNumber,
                const string& customerName,
                double balance) {
        this->accountNumber = accountNumber;
        this->customerName = customerName;
        this->balance = balance;

        totalAccounts++;
    }

    // Display account details
    void displayAccount() const {
        cout << "Account Number : "
             << accountNumber << '\n';
        cout << "Customer Name  : "
             << customerName << '\n';
        cout << "Balance        : Rs. "
             << fixed << setprecision(2)
             << balance << '\n';
    }

    // Deposit money
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit rejected: "
                 << "amount must be positive.\n";
            return;
        }

        balance += amount;
        cout << "Deposit successful: Rs. "
             << amount << '\n';
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal rejected: "
                 << "amount must be positive.\n";
        }
        else if (amount > balance) {
            cout << "Withdrawal rejected: "
                 << "insufficient balance.\n";
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful: Rs. "
                 << amount << '\n';
        }
    }

    // Inline function
    inline double getBalance() const {
        return this->balance;
    }

    // Static member function
    static void showTotalAccounts() {
        cout << "Total accounts created: "
             << totalAccounts << '\n';
    }

    // Friend class declaration
    friend class BankAudit;
};

// Initialize static data member
int BankAccount::totalAccounts = 0;

// Friend class
class BankAudit {
public:
    void printAudit(const BankAccount& account) const {
        cout << "\n--- BANK AUDIT REPORT ---\n";

        cout << "Account Number : "
             << account.accountNumber << '\n';

        cout << "Customer Name  : "
             << account.customerName << '\n';

        cout << "Verified Balance: Rs. "
             << fixed << setprecision(2)
             << account.balance << '\n';

        cout << "-------------------------\n";
    }
};

int main() {
    cout << "SMART BANKING AND ATM MANAGEMENT SYSTEM\n\n";

    // Create two account objects
    BankAccount account1(1001, "Asha", 5000.00);
    BankAccount account2(1002, "Rahul", 2000.00);

    cout << "INITIAL ACCOUNT DETAILS\n";
    account1.displayAccount();

    cout << '\n';
    account2.displayAccount();

    // Banking transactions
    cout << "\nTRANSACTIONS FOR ACCOUNT 1001\n";
    account1.deposit(1500.00);
    account1.withdraw(2000.00);

    cout << "\nTRANSACTION FOR ACCOUNT 1002\n";
    account2.withdraw(9000.00);

    // Inline function
    cout << "\nBALANCE CHECK\n";
    cout << "Asha's current balance: Rs. "
         << fixed << setprecision(2)
         << account1.getBalance() << '\n';

    // Static member function
    cout << "\nACCOUNT STATISTICS\n";
    BankAccount::showTotalAccounts();

    // Friend class
    BankAudit auditor;
    auditor.printAudit(account1);

    cout << "\nProgram completed successfully.\n";

    return 0;
}
