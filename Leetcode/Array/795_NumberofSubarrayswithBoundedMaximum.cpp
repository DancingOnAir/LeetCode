//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int numSubarrayBoundedMax(vector<int>& A, int L, int R)
//{
//    int prev = 0, res = 0, index = -1;
//
//    for (int i = 0; i < A.size(); ++i)
//    {
//        if (A[i] < L)
//        {
//            res += prev;
//        }
//        else if (A[i] > R)
//        {
//            prev = 0;
//            index = i;
//        }
//        else
//        {
//            int amount = i - index;
//            prev = amount;
//            res += amount;
//        }
//    }
//
//    return res;
//}
//
//int getValue(int target, int L, int R)
//{
//    if (target < L)
//        return -1;
//    else if (target > R)
//        return 1;
//    else
//        return 0;
//}
//
//int numSubarrayBoundedMax2(vector<int>& A, int L, int R)
//{
//    int res = 0, continueLess = 0, lastAns = 0;
//
//    for (int i = 0; i < A.size(); ++i)
//    {
//        int val = getValue(A[i], L, R);
//        if (val == 1)
//        {
//            lastAns = 0;
//            continueLess = 0;
//        }
//        else if (val == -1)
//            ++continueLess;
//        else
//        {
//            lastAns += continueLess + 1;
//            continueLess = 0;
//        }
//
//        res += lastAns;
//    }
//
//    return res;
//}
//
//void testNumSubarrayBoundedMax()
//{
//    vector<int> A = { 2, 1, 4, 3 };
//    int L = 2;
//    int R = 3;
//
//    cout << numSubarrayBoundedMax2(A, L, R) << endl;
//}
//
//int main()
//{
//    testNumSubarrayBoundedMax();
//
//    getchar();
//    return 0;
//}