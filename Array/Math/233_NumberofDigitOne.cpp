#include <iostream>


using namespace std;

int countDigitOne(int n)
{
    if (n < 1)
        return 0;
    
    int res = 0;
    while (n > 0)
    {
        int digit = n % 10;
        n /= 10;
    }

    return res;
}

void testCountDigitOne()
{
    cout << countDigitOne(13) << endl;
}

int main()
{
    testCountDigitOne();

    getchar();
    return 0;
}