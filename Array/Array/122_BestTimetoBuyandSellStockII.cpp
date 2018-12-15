//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int maxProfit(vector<int>& prices)
//{
//    if (prices.size() < 2)
//        return 0;
//
//    int res = 0;
//    for (auto i = 0; i < prices.size() - 1; ++i)
//        res += max(0, prices[i + 1] - prices[i]);
//
//    return res;
//}
//
//void testMaxProfit()
//{
//    vector<int> prices = { 7,1,5,3,6,4 };
//    cout << maxProfit(prices) << endl;
//}
//
//int main()
//{
//    testMaxProfit();
//    getchar();
//}