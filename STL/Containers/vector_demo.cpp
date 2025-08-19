#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main()
{
    vector<int> list = {10, 12, 13};
    list.push_back(14);
    for (int num: list){
        cout << num << endl;
    }
    return 0;
}