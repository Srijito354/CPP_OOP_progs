// Demostration of Compile-time polymorphism, using funciton overloading.

#include <iostream>
using namespace std;

class Calculator{
public:
    int add(int a, int b)
    {
        return a+b;
    }

    double add(double a, double b)
    {
        return a+b;
    }
};

int main()
{
    Calculator calc;
    cout << calc.add(2, 3) << endl;
    cout << calc.add(2.5, 3.5) << endl;
    return 0;
}