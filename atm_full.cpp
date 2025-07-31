
#include <iostream>
#include <limits> // for numeric_limits
using namespace std;

// Global account data
double balance = 1000.00; // Starting balance
const int correctPIN = 1234; // Default PIN

// Login function
bool login() {
    int pin;
    cout << "Enter your 4-digit PIN: ";
    cin >> pin;

    if (pin == correctPIN) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Incorrect PIN. Access denied.\n";
        return false;
    }
}

// Display menu
void showMenu() {
    cout << "\n========== ATM MENU ==========\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
    cout << "================================\n";
}

// Check balance
void checkBalance() {
    cout << "Your current balance is: R" << balance << endl;
}

// Deposit money
void deposit() {
    double amount;
    cout << "Enter amount to deposit: R";
    cin >> amount;

    if (cin.fail() || amount <= 0) {
        cout << "Invalid amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
        balance += amount;
        cout << "Deposit successful. New balance: R" << balance << endl;
    }
}

// Withdraw money
void withdraw() {
    double amount;
    cout << "Enter amount to withdraw: R";
    cin >> amount;

    if (cin.fail() || amount <= 0) {
        cout << "Invalid amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else if (amount > balance) {
        cout << "Insufficient funds.\n";
    } else {
        balance -= amount;
        cout << "Withdrawal successful. New balance: R" << balance << endl;
    }
}

// Main function
int main() {
    cout << "===== Welcome to ATM System =====\n";

    if (!login()) {
        return 1;
    }

    int choice;
    do {
        showMenu();
        cout << "Select an option (1-4): ";
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
            case 4:
                cout << "Thank you for using the ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
