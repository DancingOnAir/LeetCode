#include <iostream>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

vector<int> findErrorNums2(vector<int>& nums)
{
    int n = nums.size();
    set<int> s(nums.begin(), nums.end());
    int duplicate = accumulate(nums.begin(), nums.end(), 0) - accumulate(s.begin(), s.end(), 0);
    int miss = (1 + n) * n / 2 - accumulate(s.begin(), s.end(), 0);

    return {duplicate, miss};
}

vector<int> findErrorNums(vector<int>& nums)
{
    vector<int> res(2);
    int n = nums.size();
    if (n < 2)
        return res;


    int miss = 0, duplicate = 0;
    for (int i = 0; i < n; ++i)
    {
        int val = abs(nums[i]);
        res[1] ^= (i + 1) ^ val;
        if (nums[val - 1] < 0)
            res[0] = val;
        else
            nums[val - 1] = - nums[val - 1];
    }

    res[1] ^= res[0];
    return res;
}

void testFindErrorNums()
{
    vector<int> nums = { 1, 2, 2, 4 };
    auto res = findErrorNums(nums);
    for (int x : res)
        cout << x << ", ";
    cout << endl;
}

int main()
{
    testFindErrorNums();

    getchar();
    return 0;
}