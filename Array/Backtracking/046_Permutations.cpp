#include <iostream>
#include <vector>

void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, int level)
{
    if (level == nums.size() - 1)
    {
        result.push_back(nums);
        return;
    }

    for (int i = level; i < nums.size(); ++i)
    {
        std::swap(nums[level], nums[i]);
        backtrack(nums, result, level + 1);
        std::swap(nums[level], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) 
{
    std::vector<std::vector<int>> result;
    backtrack(nums, result, 0);

    return result;
}

int main()
{
    std::vector<int> input = { 1, 2, 3 };
    std::vector<std::vector<int>> result = permute(input);

    for (auto row : result)
    {
        for (auto col : row)
        {
            std::cout << col << ", ";
        }

        std::cout << std::endl;
    }

    system("pause");
    return 0;
}