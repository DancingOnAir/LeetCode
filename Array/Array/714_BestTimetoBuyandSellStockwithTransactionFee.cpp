//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int maxProfit(vector<int>& prices, int fee)
//{
//    int n = prices.size();
//    if (n < 2)
//        return 0;
//
//    vector<int> buy(n, 0), sell(n, 0);
//    buy[0] = -prices[0];
//
//    for (int i = 1; i < n; ++i)
//    {
//        buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
//        sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
//    }
//
//    return sell[n - 1];
//}
//
//void testMaxProfit()
//{
//    vector<int> prices = { 1, 3, 2, 8, 4, 9 };
//    int fee = 2;
//    cout << maxProfit(prices, fee) << endl;
//}
//
//int main()
//{
//    testMaxProfit();
//
//    getchar();
//    return 0;
//}