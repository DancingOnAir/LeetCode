#include <iostream>

using namespace std;

bool isPerfectSquare(int num)
{
    if (num < 0)
        return false;

    return true;
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