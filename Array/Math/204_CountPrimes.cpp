#include <iostream>
#include <math.h>
using namespace std;

int countPrimes(int n)
{
    if (n < 2)
        return 0;

    int res = 0;
    for (int i = 2; i < n; ++i)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= i; ++j)
        {
            if (0 == i % j)
            {
                isPrime = false;
                break;
            }

        }

        if (isPrime)
            ++res;
    }

    return res;
}

void testCountPrimes()
{
    cout << countPrimes(10) << endl;
    cout << countPrimes(12) << endl;
}

int main()
{
    testCountPrimes();

    getchar();
    return 0;
}