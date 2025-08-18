#include <memory>
#include <iostream>
using namespace std;

int main()
{
    unique_ptr<int> uptr = make_unique<int>(20);
    cout << *uptr << endl;

    return 0;
}

// Key features:-
// Single owner: Only one unique pointer can point to the resource.
// No copying: Copying is disabled. Use, 'std::move' to transfer ownership.
// Automatic clean-up: Memory is automatically cleaned when the unique pointer is destroyed. No need for 'delete'.