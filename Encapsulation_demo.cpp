#include <iostream>
using namespace std;

class Bank{
private:
    double bankBalance;

public:

    Bank(double b) : bankBalance(b) {}

    void displayBalance()
    {
        cout << bankBalance << endl;
    }
    int setBalance(int balance)
    {
        bankBalance = balance;
        return bankBalance;
    }
};

int main()
{
    Bank bank(1000);
    bank.displayBalance();
    bank.setBalance(10000);
    bank.displayBalance();
}