//#include <iostream>
//#include <vector>
//
//void backtrack(std::vector<int>& nums, std::vector<std::vector<int>> &result, std::vector<int> &temp, int level, int size)
//{
//    if (level >= size)
//    {
//        //auto iter = std::find(result.begin(), result.end(), temp);
//        //if (iter == result.end())
//            result.push_back(temp);
//
//        return;
//    }
//
//    //temp.push_back(nums[level]);
//    //++level;
//    //backtrack(nums, result, temp, level, size);
//    //temp.pop_back();
//    //backtrack(nums, result, temp, level, size);
//    for (int i = level; i < size; ++i)
//    {
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
//    std::vector<int> input = { 1, 2, 2 };
//    std::vector<std::vector<int>> result = subsetsWithDup(input);
//
//    display(result);
//
//    system("pause");
//    return 0;
//}