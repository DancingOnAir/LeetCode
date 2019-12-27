//#include <iostream>
//#include <vector>
//
//void rotate(std::vector<int>& nums, int k) 
//{
//    if (k < 0)
//        return;
//
//    int pos = k % nums.size();
//
//    std::vector<int> result;
//
//    result.insert(result.begin(), nums.begin() + nums.size() - pos, nums.end());
//    result.insert(result.begin() + pos, nums.begin(), nums.begin() + nums.size() - pos);
//
//    nums = result;
//}
//
//void rotate2(std::vector<int> &nums, int k)
//{
//    k = k % nums.size();
//
//    std::reverse(nums.begin(), nums.end());
//    std::reverse(nums.begin(), nums.begin() + k);
//    std::reverse(nums.begin() + k, nums.end());
//}
//
//int main()
//{
//    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7};
//    int k = 3;
//    rotate2(input, k);
//
//    for (int x : input)
//        std::cout << x << ", ";
//
//    std::cout << std::endl;
//
//    system("pause");
//    return 0;
//}