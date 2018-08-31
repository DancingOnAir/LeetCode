//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//void backtrack(std::vector<int>& nums, std::vector<std::vector<int>> &result, std::vector<int> &temp, int level, int size)
//{
//    result.push_back(temp);
//
//    for (int i = level; i < size; ++i)
//    {
//        if (i > level && nums[i] == nums[i - 1])
//            continue;
//
//        temp.push_back(nums[i]);
//        backtrack(nums, result, temp, i + 1, size);
//        temp.pop_back();
//    }
//}
//
//std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
//{
//    std::vector<std::vector<int>> result;
//    std::vector<int> temp;
//    std::sort(nums.begin(), nums.end());
//    backtrack(nums, result, temp, 0, nums.size());
//
//    return result;
//}
//
//void display(std::vector<std::vector<int>> input)
//{
//    for (auto row : input)
//    {
//        for (auto col : row)
//            std::cout << col << ", ";
//        std::cout << std::endl;
//    }
//}
//
//int main()
//{
//    std::vector<int> input = { 1, 2, 2, 2 };
//    std::vector<std::vector<int>> result = subsetsWithDup(input);
//
//    display(result);
//
//    system("pause");
//    return 0;
//}