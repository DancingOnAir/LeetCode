#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int findNthDigit(int n)
{
    if (n < 1)
        return 0;

    --n;

    int first = 0;
    for (int i = 1; i < 11; ++i)
    {
        first = pow(10, i - 1);
        if (n < (long long)9 * first * i)
            return (to_string(first + n / i)[n % i] - '0');

        n -= 9 * first * i;
    }

    return 0;
}

void testFindNthDigit()
{
    cout << findNthDigit(3) << endl;
    cout << findNthDigit(11) << endl;
    cout << findNthDigit(190) << endl;
}

int main()
{
    testFindNthDigit();

    getchar();
    return 0;
}