#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    return (((long long)n - 1) & (long long)n) == 0;
}

void testIsPowerOfTwo()
{
    cout << (isPowerOfTwo(1) ? "T" : "F") << endl;
    cout << (isPowerOfTwo(16) ? "T" : "F") << endl;
    cout << (isPowerOfTwo(218) ? "T" : "F") << endl;
    cout << (isPowerOfTwo(1024) ? "T" : "F") << endl;
}

int main()
{
    testIsPowerOfTwo();

    getchar();
    return 0;
}