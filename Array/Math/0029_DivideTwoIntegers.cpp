#include <iostream>
#include <algorithm>

using namespace std;

int divide(int dividend, int divisor)
{
    if (-1 == divisor || INT_MIN == dividend)
        return INT_MAX;

    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

    long long res = 0;
    long long dvd = llabs(dividend);
    long long dvs = llabs(divisor);

    while (dvd >= dvs)
    {
        long long temp = dvs, m = 1;
        while (temp << 1 <= dvd)
        {
            temp <<= 1;
            m <<= 1;
        }

        dvd -= temp;
        res += m;
    }

    return sign * res;
}

void testDivide()
{
    cout << divide(10, 3) << endl;
    cout << divide(7, -3) << endl;
}

int main()
{
    testDivide();

    getchar();
    return 0;
}