#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
    if (nums.size() < 2)
        return false;

    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (m.find(nums[i]) == m.end())
            m[nums[i]] = i;
        else
            return true;
    }

    return false;
}

bool containsDuplicate(vector<int>& nums)
{
    return set<int>(nums.begin(), nums.end()).size() < nums.size();
}

void testContainDuplicate()
{
    vector<int> nums = { 1,1,1,3,3,4,3,2,4,2 };
    vector<int> nums2 = { 1,2,3,4 };
    cout << (containsDuplicate(nums2) ? "true" : "false") << endl;
}

int main()
{
    testContainDuplicate();
    getchar();
}