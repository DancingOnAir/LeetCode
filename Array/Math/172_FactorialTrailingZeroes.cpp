#include <iostream>
#include <math.h>

using namespace std;

int trailingZeroes(int n)
{
    int res = 0;
    while (n > 0)
    {
        n /= 5;
        res += n;
    }

    return res;
}

void testTrailingZeroes()
{
    cout << trailingZeroes(3) << endl;
    cout << trailingZeroes(5) << endl;
    cout << trailingZeroes(30) << endl;
}

int main()
{
    testTrailingZeroes();

    getchar();
    return 0;
}