//#include <iostream>
//#include <vector>
//
//using namespace std;
//void backtrack(vector<vector<int>>& result, vector<int>& temp, int n, int k, int depth)
//{
//    if (temp.size() == k)
//    {
//        result.push_back(temp);
//        return;
//    }
//
//    for (int i = depth; i < n; ++i)
//    {
//        temp.push_back(i + 1);
//        backtrack(result, temp, n, k, i + 1);
//        temp.pop_back();
//    }
//}
//
//vector<vector<int>> combine(int n, int k) 
//{
//    vector<vector<int>> result;
//    vector<int> temp;
//    backtrack(result, temp, n, k, 0);
//
//    return result;
//}
//
//int main()
//{
//    vector<vector<int>> result = combine(4, 2);
//
//    for (auto r : result)
//    {
//        for (auto col : r)
//            cout << col << ", ";
//        cout << endl;
//    }
//
//    system("pause");
//    return 0;
//}