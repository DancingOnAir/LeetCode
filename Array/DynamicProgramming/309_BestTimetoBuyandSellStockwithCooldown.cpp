//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int maxProfit(vector<int>& prices)
//{
//    if (prices.empty())
//        return 0;
//
//    int preSell = 0, sell = 0, preBuy = 0, buy = INT_MIN;
//
//    for (int i = 0; i < prices.size(); ++i)
//    {
//        preBuy = buy;
//        buy = max(preBuy, preSell - prices[i]);
//
//        preSell = sell;
//        sell = max(preSell, preBuy + prices[i]);
//    }
//
//    return sell;
//}
//
//void testMaxProfit()
//{
//    vector<int> prices = { 1,2,3,0,2 };
//    cout << maxProfit(prices) << endl;
//}
//
//int main()
//{
//    testMaxProfit();
//
//    getchar();
//    return 0;
//}