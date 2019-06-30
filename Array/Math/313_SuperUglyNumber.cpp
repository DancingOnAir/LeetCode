#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int nthSuperUglyNumber2(int n, vector<int>& primes)
{
    if (n < 1 || primes.empty())
        return -1;

    if (1 == n)
        return 1;

    int len = primes.size();
    int res = 0;
    for (int i = 2, j = 1; j < n; ++i)
    {
        int temp = i;
        while (temp > 1)
        {
            int flag = temp;
            for (int x : primes)
            {
                if (temp % x == 0)
                    temp /= x;
            }

            if (flag == temp)
            {
                break;
            }
        }

        if (temp == 1)
        {
            ++j;
            res = i;
        }
    }

    return res;
}

int nthSuperUglyNumber(int n, vector<int>& primes)
{
    vector<int> index(primes.size());
    vector<int> ugly(n, INT_MAX);
    ugly[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < primes.size(); ++j)
            ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
        for (int j = 0; j < primes.size(); ++j)
            index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
    }

    return ugly[n - 1];
}

void testNthSuperUglyNumber()
{
    vector<int> primes{ 2, 7, 13, 19 };
    cout << nthSuperUglyNumber(12, primes) << endl;
}

int main()
{
    testNthSuperUglyNumber();

    getchar();
    return 0;
}