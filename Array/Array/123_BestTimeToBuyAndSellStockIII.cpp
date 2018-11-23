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
//    int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
//
//    for (int& x : prices)
//    {
//        sell2 = max(sell2, buy2 + x);
//        buy2 = max(buy2, sell1 - x);
//        sell1 = max(sell1, buy1 + x);
//        buy1 = max(buy1, -x);
//    }
//
//    return sell2;
//}
//
//void testMaxProfit()
//{
//    vector<int> prices = { 3, 3, 5, 0, 0, 3, 1, 4 };
//    cout << maxProfit(prices) << endl;
//}
//
//int main()
//{
//    testMaxProfit();
//    getchar();
//}