#include <iostream>

using namespace std;

bool isPerfectSquare(int num)
{
    if (num < 1)
        return false;

    long x = num;
    while (x * x > num)
    {
        x = (x + num / x) / 2;
    }

    return x * x == num;
}

void testIsPerfectSquare()
{
    cout << (isPerfectSquare(16) ? "T" : "F") << endl;
    cout << (isPerfectSquare(14) ? "T" : "F") << endl;
}

int main()
{
    testIsPerfectSquare();

    getchar();
    return 0;
}