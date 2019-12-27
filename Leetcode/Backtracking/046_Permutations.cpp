//#include <iostream>
//#include <vector>
//
//void backtrack1(std::vector<int>& nums, std::vector<std::vector<int>>& result, int level)
//{
//    if (level == nums.size() - 1)
//    {
//        result.push_back(nums);
//        return;
//    }
//
//    for (int i = level; i < nums.size(); ++i)
//    {
//        std::swap(nums[level], nums[i]);
//        backtrack1(nums, result, level + 1);
//        std::swap(nums[level], nums[i]);
//    }
//}
//
//void backtrack2(std::vector<int>& nums, std::vector<std::vector<int>>& result, int k, std::vector<bool>& isUsed, std::vector<int>& current)
//{
//    if (k == nums.size())
//    {
//        result.push_back(current);
//        return;
//    }
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        if (!isUsed[i])
//        {
//            isUsed[i] = true;
//            current.push_back(nums[i]);
//            
//            backtrack2(nums, result, k + 1, isUsed, current);
//            current.pop_back();
//            isUsed[i] = false;
//        }
//    }
//}
//
//std::vector<std::vector<int>> permute(std::vector<int>& nums) 
//{
//    std::vector<std::vector<int>> result;
//    std::vector<bool> isUsed(nums.size(), false);
//    std::vector<int> current;
//
//    //backtrack1(nums, result, 0);
//    backtrack2(nums, result, 0, isUsed, current);
//    return result;
//}
//
//int main()
//{
//    std::vector<int> input = { 1, 2, 3 };
//    std::vector<std::vector<int>> result = permute(input);
//
//    for (auto row : result)
//    {
//        for (auto col : row)
//        {
//            std::cout << col << ", ";
//        }
//
//        std::cout << std::endl;
//    }
//
//    system("pause");
//    return 0;
//}