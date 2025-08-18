#include <memory>
#include <iostream>
using namespace std;

class Student{
private:
    string name;

public:
    Student(string s) : name(s) {}
    string action()
    {
        unique_ptr<string> utpr = make_unique<string>(name);
        return *utpr;
    }
};

int main()
{
    Student student("Srijito Ghosh");
    cout << student.action() << endl;
    return 0;
}