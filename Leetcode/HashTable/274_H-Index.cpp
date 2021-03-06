//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int hIndex2(vector<int>& citations)
//{
//    if (citations.empty())
//        return 0;
//
//    sort(citations.begin(), citations.end());
//    int len = citations.size();
//    for (auto i = 0; i < len; ++i)
//    {
//        if (citations[i] >= len - i)
//            return len - i;
//    }
//
//    return 0;
//}
//
//int hIndex(vector<int>& citations)
//{
//    if (citations.empty())
//        return 0;
//
//    int n = citations.size();
//    vector<int> h(n + 1);
//
//    for (int x : citations)
//    {
//        if (x > n)
//            h[n]++;
//        else
//            h[x]++;
//    }
//
//    int paper = 0;
//    for (int i = n; i >= 0; --i)
//    {
//        paper += h[i];
//        if (paper >= i)
//            return i;
//    }
//}
//
//void testHIndex()
//{
//    vector<int> citations1 = { 2, 0, 6, 1, 5 };
//    cout << hIndex(citations1) << endl;
//
//    vector<int> citations2 = { 1, 2, 3, 4, 6, 4, 8, 9, 7, 10 };
//    cout << hIndex(citations2) << endl;
//}
//
//int main()
//{
//    testHIndex();
//
//    getchar();
//    return 0;
//}