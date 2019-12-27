//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int checkRecord(int n)
//{
//    if (n <= 0)
//        return 0;
//    //0 not include A, end without L
//    //1 not include A, end with 1 L
//    //2 not include A, end with 2 L
//    //3 include A, end without L
//    //4 include A, end with 1 L
//    //5 include A, end with 2 L
//    vector<long long> res = { 1, 1, 0, 1, 0, 0 };
//    long long prime = 10e9 + 7;
//
//    for (int i = 0; i < n - 1; ++i)
//    {
//        vector<long long> dp(6);
//        dp[0] = (res[0] + res[1] + res[2]) % prime;
//        dp[1] = res[0];
//        dp[2] = res[1];
//        dp[3] = (res[0] + res[1] + res[2] + res[3] + res[4] + res[5]) % prime;
//        dp[4] = res[3];
//        dp[5] = res[4];
//
//        res.swap(dp);
//    }
//    
//    return (res[0] + res[1] + res[2] + res[3] + res[4] + res[5]) % prime;
//}
//
//void testCheckRecord()
//{
//    cout << checkRecord(1) << endl;
//    cout << checkRecord(2) << endl;
//}
//
//int main()
//{
//    testCheckRecord();
//
//    getchar();
//    return 0;
//}