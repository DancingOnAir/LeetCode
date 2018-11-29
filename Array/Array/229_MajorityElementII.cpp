#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
    vector<int> result;
    if (nums.empty())
        return result;

    size_t len = nums.size();
    auto times = len / 3;

    std::sort(nums.begin(), nums.end());

    for (auto i = 0; i < len;)
    {
        int start = i, end = i;
        while (end + 1 < len && nums[end] == nums[end + 1])
        {
            ++end;
        }

        if (end - start + 1 > times)
            result.emplace_back(nums[start]);

        i = end + 1;

    }
    return result;
}

vector<int> majorityElement2(vector<int>& nums)
{
    vector<int> result;
    if (nums.empty())
        return result;

    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    for (auto x : nums)
    {
        if (x == candidate1)
            ++count1;
        else if (x == candidate2)
            ++count2;
        else if (0 == count1)
            candidate1 = x, count1 = 1;
        else if (0 == count2)
            candidate2 = x, count2 = 1;
        else
            --count1, --count2;
    }

    count1 = count2 = 0;
    for (auto x : nums)
    {
        if (x == candidate1) ++count1;
        else if (x == candidate2) ++count2;
    }

    if (count1 > nums.size() / 3)
        result.emplace_back(candidate1);

    if (count2 > nums.size() / 3)
        result.emplace_back(candidate2);

    return result;
}

void display(vector<int>& nums)
{
    if (nums.empty())
        return;

    for (auto x : nums)
        cout << x << ",";
    cout << endl;
}

void testMajorityElement()
{
    vector<int> nums = { 1,1,1,3,3,2,2,2 };
    vector<int> nums2 = { -1, 1, 1, 1, 2, 1 };
    auto result = majorityElement2(nums2);
    display(result);
}

int main()
{
    testMajorityElement();
    getchar();
}