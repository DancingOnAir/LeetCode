#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    if (amount == 0)
        return 0;

    if (coins.empty())
        return -1;

    sort(coins.begin(), coins.end());
    vector<int> dp(amount + 1, 0x3f3f3f3f);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
    {
        for (int j = 0; j < coins.size(); ++j)
        {
            if (coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

void testCoinChange()
{
    vector<int> coins{ 1, 11, 12 };
    int amount = 11;

    cout << coinChange(coins, amount) << endl;
}

int main()
{
    testCoinChange();

    getchar();
    return 0;
}