#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    int* ptr = &num;

    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << ptr << endl;
    cout << "Address of num, using Address of operator: " << &num << endl;
    cout << "Value of num via pointer: " << *ptr << endl;
    return 0;
}