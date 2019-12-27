//#include <iostream>
//#include <vector>
//#include <set>
//#include <algorithm>
//using namespace std;
//
////void backtrack(std::vector<std::vector<int>>& result, vector<int>& temp, std::vector<int>& candidates, int target, int depth)
////{
////    int sum = 0;
////    for (int x : temp)
////    {
////        sum += x;
////    }
////
////    if (sum > target)
////        return;
////
////    if (sum == target)
////    {
////        multiset<int> s1, s2;
////        bool isDuplicated = false;
////        s1.insert(temp.begin(), temp.end());
////        for (auto row : result)
////        {
////            s2.insert(row.begin(), row.end());
////            if (s2 == s1)
////            {
////                isDuplicated = true;
////                break;
////            }
////            s2.clear();
////        }
////
////        if (false == isDuplicated)
////            result.push_back(temp);
////        return;
////    }
////
////    for (int i = 0; i < candidates.size(); ++i)
////    {
////        temp.push_back(candidates[i]);
////        backtrack(result, temp, candidates, target, i + 1);
////        temp.pop_back();
////    }
////}
//
//void backtrack(std::vector<std::vector<int>>& result, vector<int>& temp, std::vector<int>& candidates, int target, int depth, int sum)
//{
//    if (depth >= candidates.size())
//        return;
//
//    if (sum == target)
//    {
//        result.push_back(temp);
//        return;
//    }
//
//    if (sum > target)
//        return;
//
//    temp.push_back(candidates[depth]);
//    backtrack(result, temp, candidates, target, depth, sum + candidates[depth]);
//    temp.pop_back();
//    backtrack(result, temp, candidates, target, depth + 1, sum);
//}
//
//std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
//{
//    std::vector<std::vector<int>> result;
//    vector<int> temp;
//
//    if (candidates.empty())
//        return result;
//
//    backtrack(result, temp, candidates, target, 0, 0);
//
//    return result;
//}
//
//int main()
//{
//    std::vector<int> candidates = { 1, 2, 3, 5 };
//    int target = 8;
//    std::vector<std::vector<int>> result = combinationSum(candidates, target);
//
//    for (auto row : result)
//    {
//        for (auto col : row)
//            cout << col << ", ";
//        cout << endl;
//    }
//
//    system("pause");
//    return 0;
//}