#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    int n = nums.size();
    long long sum1 = n * (n + 1) / 2;
    long long sum2 = 0;
    for (auto& x : nums)
        sum2 += x;

    return sum1 - sum2;
}

int missingNumber2(vector<int>& nums)
{
    int result = nums.size();
    int i = 0;
    for (auto& x : nums)
    {
        result ^= x;
        result ^= i;
        ++i;
    }

    return result;
}

void testMissingNumber()
{
    vector<int> nums = { 9,6,4,2,3,5,7,0,1 };
    cout << missingNumber2(nums) << endl;
}

int main()
{
    testMissingNumber();
    getchar();
}