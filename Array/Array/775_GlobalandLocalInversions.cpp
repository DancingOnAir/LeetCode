//#include <iostream>
//#include <vector>
//using namespace std;
//
//int calculateNumOfInversion(vector<int>& nums, int pos)
//{
//    int res = 0;
//    for (int i = 0; i < pos; ++i)
//    {
//        if (nums[i] > nums[pos])
//            ++res;
//    }
//
//    return res;
//}
//
//bool isIdealPermutation(vector<int>& A)
//{
//    int n = A.size();
//    if (n < 3)
//        return true;
//
//    vector<int> dp(n + 1);
//    dp[0] = 0;
//    
//    int cnt = 0;
//
//    for (int i = 1; i < n; ++i)
//    {
//        dp[i] = dp[i - 1] + calculateNumOfInversion(A, i);
//        
//        if (A[i] < A[i - 1])
//            ++cnt;
//    }
//    
//    return cnt == dp[n - 1];
//}
//
//bool isIdealPermutation2(vector<int>& A)
//{
//    for (int i = 0; i < A.size(); ++i)
//    {
//        if (abs(A[i] - i) > 1)
//            return false;
//    }
//
//    return true;
//}
//
//void testIsIdealPermutation()
//{
//    vector<int> nums = { 1, 0, 2 };
//    vector<int> nums2 = { 1, 2, 0 };
//    cout << (isIdealPermutation2(nums2)? "true":"false") << endl;
//}
//
//int main()
//{
//    testIsIdealPermutation();
//
//    getchar();
//    return 0;
//}