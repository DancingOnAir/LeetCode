#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int findLHS(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    map<int, int> count;
    for (int i : nums)
        ++count[i];

    int res = 0;
    for (auto iter = count.begin(); iter != count.end(); ++iter)
    {
        if (count.count(iter->first + 1))
            res = max(res, iter->second + count[iter->first + 1]);
    }

    return res;
}

void testFindLHS()
{
    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    cout << findLHS(nums) << endl;
}

int main()
{
    testFindLHS();

    getchar();
    return 0;
}