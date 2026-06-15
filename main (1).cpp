#include <iostream>
using namespace std;

class Transaction
{
public:
    string history[100];
    int count;

    Transaction()
    {
        count = 0;
    }

    void addTransaction(string msg)
    {
        history[count] = msg;
        count++;
    }

    void showHistory()
    {
        cout << "\nTransaction History:\n";

        for(int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
};

class Account
{
private:
    int accountNumber;
    string customerName;
    double balance;

public:
    Transaction t;

    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Customer Name: ";
        cin >> customerName;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        t.addTransaction("Account Created");
    }

    void deposit()
    {
        double amount;

        cout << "Enter Deposit Amount: ";
        cin >> amount;

        balance += amount;

        t.addTransaction("Deposited Money");

        cout << "Deposit Successful!" << endl;
    }

    void withdraw()
    {
        double amount;

        cout << "Enter Withdrawal Amount: ";
        cin >> amount;

        if(amount <= balance)
        {
            balance -= amount;

            t.addTransaction("Withdrawn Money");

            cout << "Withdrawal Successful!" << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void transfer()
    {
        double amount;

        cout << "Enter Transfer Amount: ";
        cin >> amount;

        if(amount <= balance)
        {
            balance -= amount;

            t.addTransaction("Fund Transfer");

            cout << "Transfer Successful!" << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void displayDetails()
    {
        cout << "\n===== ACCOUNT DETAILS =====" << endl;

        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : " << balance << endl;
    }

    void showTransactions()
    {
        t.showHistory();
    }
};

int main()
{
    Account acc;

    int choice;

    acc.createAccount();

    do
    {
        cout << "\n===== BANKING SYSTEM =====";
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Fund Transfer";
        cout << "\n4. Account Details";
        cout << "\n5. Transaction History";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                acc.deposit();
                break;

            case 2:
                acc.withdraw();
                break;

            case 3:
                acc.transfer();
                break;

            case 4:
                acc.displayDetails();
                break;

            case 5:
                acc.showTransactions();
                break;

            case 6:
                cout << "\nThank You!" << endl;
                break;

            default:
                cout << "\nInvalid Choice!" << endl;
        }

    } while(choice != 6);

    return 0;
}SSS