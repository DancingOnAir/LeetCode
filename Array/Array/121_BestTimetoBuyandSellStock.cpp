#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices)
{
    if (prices.empty())
        return 0;

    int buy = INT_MIN, sell = 0;
    for (auto& x : prices)
    {
        buy = max(buy, -x);
        sell = max(sell, buy + x);
    }

    return sell;
}

void testMaxProfit()
{
    vector<int> prices = { 7,1,5,3,6,4 };
    cout << maxProfit(prices) << endl;
}

int main()
{
    testMaxProfit();
    getchar();
}