#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {1, 0, 10, 5, 6};

    sort(nums.begin(), nums.end(), [](int a, int b) {return a < b;});
    
    for (auto num : nums)
    {
        cout << num << endl;
    }
    return 0;
}