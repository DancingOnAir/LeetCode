#include <iostream>

using namespace std;

bool isUgly(int num)
{
    if (num < 1)
        return false;

    if (1 == num)
        return true;

    while (num > 1)
    {
        if (num % 2 == 0)
            num /= 2;
        else if (num % 3 == 0)
            num /= 3;
        else if (num % 5 == 0)
            num /= 5;
        else
            return false;
    }

    return true;
}

void testIsUgly()
{
    cout << (isUgly(6) ? "T" : "F") << endl;
    cout << (isUgly(8) ? "T" : "F") << endl;
    cout << (isUgly(14) ? "T" : "F") << endl;
}

int main()
{
    testIsUgly();

    getchar();
    return 0;
}