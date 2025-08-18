#include <memory>
#include <iostream>
using namespace std;

int main()
{
    auto sptr = make_shared<int>(50);
    weak_ptr<int> wptr = sptr;

    if (auto temp = wptr.lock())
    {
        cout << *temp << endl;
    }
    return 0;
}