//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int maxRotateFunction2(vector<int>& A)
//{
//    if (A.empty())
//        return 0;
//
//    int res = INT_MIN;
//    int len = A.size();
//    for (int i = 0; i < len; ++i)
//    {
//        int sum = 0;
//        for (int j = 0; j < len; ++j)
//        {
//            sum += j * A[((-i + len) % len + j) % len];
//        }
//        res = max(res, sum);
//    }
//
//    return res;
//}
//
//int maxRotateFunction(vector<int>& A)
//{
//    if (A.empty())
//        return 0;
//
//    int f0 = 0, sum = 0;
//    for (int i = 0; i < A.size(); ++i)
//    {
//        f0 += i * A[i];
//        sum += A[i];
//    }
//
//    int res = f0, temp = f0;
//    for (int i = 1; i < A.size(); ++i)
//    {
//        temp += sum - A.size() * A[A.size() - i];
//        res = max(res, temp);
//    }
//
//    return res;
//}
//
//void testMaxRotateFunction()
//{
//    vector<int> A1 = { 4, 3, 2, 6 };
//    cout << maxRotateFunction(A1) << endl;
//}
//
//int main()
//{
//    testMaxRotateFunction();
//
//    getchar();
//    return 0;
//}