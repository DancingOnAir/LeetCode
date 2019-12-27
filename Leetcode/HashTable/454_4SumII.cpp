//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
//{
//    unordered_map<int, int> AB;
//    for (int a : A)
//    {
//        for (int b : B)
//            ++AB[a + b];
//    }
//
//    int res = 0;
//    for (int c : C)
//    {
//        for (int d : D)
//        {
//            if (AB.find(- c - d) != AB.end())
//                res += AB[-c - d];
//        }
//    }
//
//    return res;
//}
//
//void testFourSumCount()
//{
//    vector<int> A = { 1, 2 };
//    vector<int> B = { -2, -1 };
//    vector<int> C = { -1, 2 };
//    vector<int> D = { 0, 2 };
//
//    cout << fourSumCount(A, B, C, D) << endl;
//}
//
//int main()
//{
//    testFourSumCount();
//
//    getchar();
//    return 0;
//}