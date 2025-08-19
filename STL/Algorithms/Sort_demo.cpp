#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {200, 10, 30, 5};
    sort(nums.begin(), nums.end());

    for (auto num:nums)
    {
        cout << num << endl;
    }
    return 0;
}