//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
//{
//    for (auto& row : A)
//    {
//        reverse(row.begin(), row.end());
//        for (auto& col : row)
//        {
//            col ^= 1;
//        }
//    }
//
//    return A;
//}
//
//vector<vector<int>> flipAndInvertImage2(vector<vector<int>>& A)
//{
//    vector<vector<int>> res;
//
//    for (auto& col : A)
//    {
//        res.resize(res.size() + 1);
//        for (auto iter = col.rbegin(); iter != col.rend(); ++iter)
//        {
//            res[res.size() - 1].emplace_back((*iter) ^ 1);
//        }
//    }
//
//    return res;
//}
//
//void testFlipAndInvertImage()
//{
//    vector<vector<int>> image = { {1, 1, 0, 0}, 
//                                {1, 0, 0, 1}, 
//                                {0, 1, 1, 1}, 
//                                {1, 0, 1, 0} };
//
//    auto res = flipAndInvertImage2(image);
//
//    for (auto& row : res)
//    {
//        for (auto& col : row)
//            cout << col << ", ";
//        cout << endl;
//    }
//}
//
//int main()
//{
//    testFlipAndInvertImage();
//
//    getchar();
//    return 0;
//}