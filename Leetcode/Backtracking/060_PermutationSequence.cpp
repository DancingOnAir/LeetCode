//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
//#include <string>
//
//using namespace std;
//
//void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<bool>& isUsed, vector<int>& current, int depth)
//{
//    if (depth == nums.size())
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
//            backtrack(nums, result, isUsed, current, depth + 1);
//            current.pop_back();
//            isUsed[i] = false;
//        }
//    }
//}
//
//string getPermutation(int n, int k) 
//{
//    vector<int> input;
//    vector<vector<int>> result;
//
//    vector<int> current;
//    for (int i = 1; i <= n; ++i)
//        input.push_back(i);
//    vector<bool> isUsed(input.size(), false);
//    backtrack(input, result, isUsed, current, 0);
//
//    string temp;
//    for (int i = 0; i < result[0].size(); ++i)
//        temp += std::to_string(result[k - 1][i]);
//    return temp;
//}
//
//string getPermutation2(int n, int k)
//{
//    string temp = "";
//    for (int i = 1; i <= n; ++i)
//        temp.push_back(i + '0');
//
//    while (--k)
//    {
//        std::next_permutation(temp.begin(), temp.end());
//    }
//
//    return temp;
//}
//
//int main()
//{
//    auto result = getPermutation2(4, 9);
//
//    cout << result << endl;
//
//    system("pause");
//    return 0;
//}