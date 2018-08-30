//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_set>
//
//void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, int level)
//{
//    if (level == nums.size() - 1)
//    {
//        result.push_back(nums);
//        return;
//    }
//    
//    std::unordered_set<int> s;
//    for (int i = level; i < nums.size(); ++i)
//    {
//        if (s.count(nums[i]))
//            continue;
//
//        s.insert(nums[i]);
//
//        std::swap(nums[level], nums[i]);
//        backtrack(nums, result, level + 1);
//        std::swap(nums[level], nums[i]);
//    }
//}
//
//std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
//{
//    std::vector<std::vector<int>> result;
//    std::unordered_set<int> s;
//
//    backtrack(nums, result, 0);
//
//    return result;
//}
//
//int main()
//{
//    std::vector<int> input = { 1, 1, 2 };
//    std::vector<std::vector<int>> result = permuteUnique(input);
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