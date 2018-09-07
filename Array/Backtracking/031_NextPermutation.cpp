#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//void backtrack(vector<int>& nums, vector<vector<int>>& result, int depth)
//{
//    if (depth == nums.size() - 1)
//    {
//        result.push_back(nums);
//        return;
//    }
//
//    for (int i = depth; i < nums.size(); ++i)
//    {
//        swap(nums[i], nums[depth]);
//        backtrack(nums, result, depth + 1);
//        swap(nums[i], nums[depth]);
//    }
//}

void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<bool> isUsed, vector<int> current, int k)
{
    if (k == nums.size())
    {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (!isUsed[i])
        {
            isUsed[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, result, isUsed, current, k + 1);
            current.pop_back();
            isUsed[i] = false;
        }
    }
}

void nextPermutation(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<bool> isUsed(nums.size(), false);
    vector<int> current;
    vector<int> temp(nums);
    int x = -1;
    std::sort(temp.begin(), temp.end());
    backtrack(temp, result, isUsed, current, 0);

    for (int i = 0; i < result.size(); ++i)
    {
        if (result[i] == nums)
        {
            x = i;
        }
    }
    
    x = (x + 1) % result.size();
    if (x >= 0)
        nums = result[x];
}


void nextPermutation2(vector<int>& nums)
{
    auto dest = is_sorted_until(nums.rbegin(), nums.rend());

    if (dest != nums.rend())
    {
        auto iter = upper_bound(nums.rbegin(), dest, *dest);
        swap(*dest, *iter);
    }


    reverse(nums.rbegin(), dest);
}

int main()
{
    vector<int> input = { 2, 4, 3, 2, 1 };
    auto iter = lower_bound(input.begin(), input.end(), 2, greater<int>());
    nextPermutation(input);

    for (auto x : input)
        cout << x << ", ";
    cout << endl;

    system("pause");
    return 0;
}