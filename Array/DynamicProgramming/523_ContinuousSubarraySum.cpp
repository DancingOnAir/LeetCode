#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k)
{
    int sum = 0;
    for (int x : nums)
        sum += x;

    if (sum < k)
        return false;

    bool res = true;

    return true;
}

void testCheckSubarraySum()
{
    vector<int> nums = { 23, 2, 4, 6, 7 };
    int k = 6;

    cout << (checkSubarraySum(nums, k) ? "T" : "F") << endl;
}

int main()
{
    testCheckSubarraySum();

    getchar();
    return 0;
}