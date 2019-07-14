#include <iostream>
#include <cmath>
using namespace std;

int arrangeCoins2(int n)
{
    if (n < 1)
        return 0;

    return floor(sqrt((double)2 * n + 0.25) - 0.5);
}

int arrangeCoins(int n)
{
    int i = 1;
    while (n > i)
        n -= i++;

    return i - 1;
}

void testArrangeCoins()
{
    cout << arrangeCoins(5) << endl;
    cout << arrangeCoins(8) << endl;
}

int main()
{
    testArrangeCoins();

    getchar();
    return 0;
}