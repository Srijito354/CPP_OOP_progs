#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {10, 12, 13, 14};

    transform(nums.begin(), nums.end(), nums.begin(), [](int x) {return x;});

    for (int num:nums)
    {
        cout << num << endl;
    }

    return 0;
}