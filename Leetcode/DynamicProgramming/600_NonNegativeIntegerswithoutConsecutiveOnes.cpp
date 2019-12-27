#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findIntegers1(int num)
{
    if (num < 0)
        return 0;

    int res = 0;
    for (int i = 0; i <= num; ++i)
    {
        if ((i & i << 1) > 0)
            continue;
        ++res;
    }

    return res;
}

int findIntegers2(int num)
{
    if (num < 0)
        return 0;

    vector<int> f(32);
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < 32; ++i)
        f[i] = f[i - 1] + f[i - 2];

    int res = 0, k = 30, pre = 0;
    while (k >= 0)
    {
        if (num & (1 << k))
        {
            res += f[k];
            if (pre)
                return res;
            pre = 1;
        }
        else
        {
            pre = 0;
        }

        --k;
    }

    return res + 1;
}

void testFindIntegers()
{
    cout << findIntegers2(5) << endl;
}

int main()
{
    testFindIntegers();

    getchar();
    return 0;
}