//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//vector<int> twoSum(vector<int>& numbers, int target)
//{
//    vector<int> result;
//    if (numbers.size() < 2)
//        return result;
//
//    unordered_map<int, int> m;
//
//    for (size_t i = 0; i < numbers.size(); ++i)
//    {
//        if (m.find(numbers[i]) == m.end())
//        {
//            m[target - numbers[i]] = i;
//        }
//        else
//        {
//            result.emplace_back(m[numbers[i]] + 1);
//            result.emplace_back(i + 1);
//        }
//    }
//
//    return result;
//}
//
//vector<int> twoSum2(vector<int>& numbers, int target)
//{
//    vector<int> result;
//    if (numbers.size() < 2)
//        return result;
//
//    int left = 0, right = numbers.size() - 1;
//    while (left < right && numbers[left] + numbers[right] != target)
//    {
//        if (numbers[left] + numbers[right] > target)
//            --right;
//        else
//            ++left;
//    }
//    return vector<int>({ left, right });
//}
//
//void testTwosum()
//{
//    vector<int> nums = { 2, 7, 11, 15 };
//    int target = 9;
//    vector<int> result = twoSum2(nums, target);
//    cout << result[0] << ", " << result[1] << endl;
//}
//
//int main()
//{
//    testTwosum();
//    getchar();
//}