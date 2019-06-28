#include <iostream>

using namespace std;

bool isPowerOfThree(int n)
{
    if (n < 1)
        return false;


    while (n % 3 == 0)
    {
        n /= 3;
    }

    if (n == 1)
        return true;

    return false;
}

void testIsPowerOfThree()
{
    cout << (isPowerOfThree(27) ? "True" : "False") << endl;
    cout << (isPowerOfThree(0) ? "True" : "False") << endl;
    cout << (isPowerOfThree(9) ? "True" : "False") << endl;
    cout << (isPowerOfThree(45) ? "True" : "False") << endl;
}

int main()
{
    testIsPowerOfThree();

    getchar();
    return 0;
}