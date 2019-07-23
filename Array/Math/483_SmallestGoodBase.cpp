#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getRemaining(long long num, long long base)
{
    int res = log(num) / log(base);
    return res;
}

string smallestGoodBase(string n)
{
    if (n.empty())
        return "";

    long long num = atoll(n.c_str());
    long long res = 2;

    while (res < num)
    {
        long long temp = getRemaining(num, res);
        if ((pow(res, temp + 1) - 1) / (res - 1) == num)
            return to_string(res);
        else
            ++res;
    }

    return "";
}

void testSmallestGoodBase()
{
    cout << smallestGoodBase("13") << endl;
    cout << smallestGoodBase("4681") << endl;
    //cout << smallestGoodBase("1000000000000000000") << endl;
}

int main()
{
    testSmallestGoodBase();

    getchar();
    return 0;
}