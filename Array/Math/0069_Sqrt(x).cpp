#include <iostream>

using namespace std;

int mySqrt(int x)
{
    if (x <= 0)
        return 0;

    double res = 1.0;
    double epsilon = 1e-4;
    while (abs(res * res - x) > epsilon)
    {
        res = (res + x / res) / 2;
    }

    return res;
}

void testMySqrt()
{

    cout << mySqrt(2) << endl;
    cout << mySqrt(3) << endl;
    cout << mySqrt(4) << endl;
    cout << mySqrt(8) << endl;
}

int main()
{
    testMySqrt();

    getchar();
    return 0;
}