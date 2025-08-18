#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> stpr1 = make_shared<int>(100);
    shared_ptr<int> stpr2 = stpr1;

    cout << *stpr1 << endl;
    cout << "Reference count: " << stpr1.use_count() << endl;

    shared_ptr<int> stpr3 = stpr1;
    cout << "Reference count: " << stpr2.use_count() << endl;
    cout << "Reference count: " << stpr3.use_count() << endl;
    return 0;
}