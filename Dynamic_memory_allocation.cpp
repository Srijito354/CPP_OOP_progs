#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int(20);
    cout << *ptr << endl;
    delete ptr;
    return 0;
}

// Issues with raw pointers:
// 1.Memory leaks: Frogetting to call delete.
// 2.Dangling pointer: Using a pointer after delete.
// 3.Manual Errors: Complex ownership management.