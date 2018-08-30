//#include <iostream>
//#include <vector>
//
//void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<int>& temp, int level, int size)
//{
//    if (level >= size)
//    {
//        result.push_back(temp);
//        return;
//    }
//
//    temp.push_back(nums[level]);
//    ++level;
//    backtrack(nums, result, temp, level, size);
//    temp.pop_back();
//    backtrack(nums, result, temp, level, size);
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
//std::vector<std::vector<int>> subsets(std::vector<int>& nums) 
//{
//    std::vector<std::vector<int>> result;
//    std::vector<int> temp;
//    backtrack(nums, result, temp, 0, nums.size());
//
//    return result;
//}
//
//int main()
//{
//    std::vector<int> input = { 1, 2, 3 };
//    std::vector<std::vector<int>> result = subsets(input);
//
//    display(result);
//
//    system("pause");
//    return 0;
//}