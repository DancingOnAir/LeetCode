#include <iostream>
#include <cmath>
using namespace std;

int arrangeCoins(int n)
{
    if (n < 1)
        return 0;

    return floor(sqrt((double)2 * n + 0.25) - 0.5);
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