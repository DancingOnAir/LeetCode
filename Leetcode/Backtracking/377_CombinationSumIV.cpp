#include <iostream>
#include <vector>
using namespace std;

//void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& nums, int target, int sum)
//{
//    if (sum > target)
//        return;
//
//    if (sum == target)
//    {
//        result.push_back(current);
//        return;
//    }
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        if (nums[i] <= target)
//        {
//            current.push_back(nums[i]);
//            backtrack(result, current, nums, target, sum + nums[i]);
//            current.pop_back();
//        }
//    }
//}
//
//std::vector<std::vector<int>> combinationSum4(vector<int>& nums, int target)
//{
//    vector<vector<int>> result;
//    vector<int> current;
//    backtrack(result, current, nums, target, 0);
//
//    return result;
//}

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if (i >= nums[j])
                dp[i] += dp[i - nums[j]];
        }
    }

    return dp[target];
}

int main()
{
    std::vector<int> candidates = { 1, 2, 3 };
    int target = 4;
    int result = combinationSum4(candidates, target);
    cout << result;

    system("pause");
    return 0;
}