#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits2(int num)
{
    if (num < 0)
        return vector<int>();

    vector<int> dp(num + 1);
    for (int i = 1; i <= num; ++i)
    {
        dp[i] = dp[i & (i - 1)] + 1;
    }

    return dp;
}

vector<int> countBits(int num)
{
    if (num < 0)
        return vector<int>();

    vector<int> dp(num + 1);
    int cur = 0, count = 0;

    for (int i = 1; i <= num; ++i)
    {
        cur = i;
        dp[i] = dp[cur >> 1] + (i & 1);
    }

    return dp;
}

void testCountBits()
{
    auto res1 = countBits(2);
    for (int x : res1)
        cout << x << ", ";
    cout << endl;

    auto res2 = countBits(5);
    for (int x : res2)
        cout << x << ", ";
    cout << endl;
}

int main()
{
    testCountBits();

    getchar();
    return 0;
}