//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int findMinMoves(vector<int>& machines)
//{
//    int n = machines.size();
//    if (n < 2)
//        return 0;
//
//    vector<int> sum(n + 1);
//    for (int i = 0; i < n; ++i)
//        sum[i + 1] += sum[i] + machines[i];
//
//    if (sum[n] % n)
//        return -1;
//
//    int avg = sum[n] / n;
//    int l = 0, r = 0;
//    int res = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        l = i * avg - sum[i];
//        r = (n - i - 1) * avg - (sum[n] - sum[i] - machines[i]);
//
//        if (l > 0 && r > 0)
//        {
//            res = max(res, abs(l) + abs(r));
//        }
//        else
//        {
//            res = max(res, max(abs(l), abs(r)));
//        }
//    }
//
//    return res;
//}
//
//void testFindMinMoves()
//{
//    vector<int> machines = { 1,0,5 };
//    cout << findMinMoves(machines) << endl;
//}
//
//int main()
//{
//    testFindMinMoves();
//
//    getchar();
//    return 0;
//}