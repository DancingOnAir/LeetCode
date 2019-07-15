#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMoves(vector<int>& nums)
{
    size_t len = nums.size();
    if (len < 2)
        return 0;

    sort(nums.begin(), nums.end());

    int res = 0;
    for (int i = len - 1; i > 0; --i)
    {
        res += nums[i] - nums[0];
    }

    return res;
}

void testMinMoves()
{
    vector<int> nums = { 1, 2, 3 };
    cout << minMoves(nums) << endl;
}

int main()
{
    testMinMoves();

    getchar();
    return 0;
}