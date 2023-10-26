#include <iostream>
#include <string>

class BankAccount {
private:
    int accountNumber;
    std::string accountHolderName;
    double accountBalance;

public:
    // Constructor to initialize the account
    BankAccount(int accNumber, const std::string& accHolderName, double initialBalance) :
        accountNumber(accNumber), accountHolderName(accHolderName), accountBalance(initialBalance) {}

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            accountBalance += amount;
            std::cout << "Deposited $" << amount << " into the account.\n";
        } else {
            std::cout << "Invalid deposit amount. Please enter a positive amount.\n";
        }
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= accountBalance) {
            accountBalance -= amount;
            std::cout << "Withdrawn $" << amount << " from the account.\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient balance.\n";
        }
    }

    // Method to display the account balance
    void displayBalance() {
        std::cout << "Account Holder: " << accountHolderName << "\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Account Balance: $" << accountBalance << "\n";
    }
};

int main() {
    // Create an instance of the BankAccount class
    BankAccount myAccount(12345, "John Doe", 1000.0);

    // Test deposit and withdrawal functionality
    myAccount.displayBalance();
    myAccount.deposit(500.0);
    myAccount.displayBalance();
    myAccount.withdraw(200.0);
    myAccount.displayBalance();
    myAccount.withdraw(1500.0);  // Attempt to withdraw more than the balance
    myAccount.deposit(-100.0);   // Attempt to deposit a negative amount

    return 0;
}
