#include <iostream>
#include <algorithm>

using namespace std;

int divide(int dividend, int divisor)
{
    if (0 == divisor || 0 == dividend)
        return 0;

    int res = 0;
    return res;
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