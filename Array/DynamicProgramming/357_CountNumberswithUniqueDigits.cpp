#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int fact(int x)
{
    if (1 == x || 0 == x)
        return 1;
    else
        return x * fact(x - 1);
}

int countNumbersWithUniqueDigits(int n)
{
    if (n < 0)
        return 0;

    vector<int> dp(n + 1);
    dp[0] = 1;
    int increase = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (0 == j)
                increase = 9;
            else
            {
                if (10 - j < 1)
                    break;

                increase *= (10 - j);
            }
        }
        dp[i] = dp[i - 1] + increase;
    }

    return dp[n];
}

void testCountNumberWithUniqueDigits()
{
    int n = 3;
    cout << countNumbersWithUniqueDigits(2) << endl;
    cout << countNumbersWithUniqueDigits(n) << endl;
}

int main()
{
    testCountNumberWithUniqueDigits();

    getchar();
    return 0;
}