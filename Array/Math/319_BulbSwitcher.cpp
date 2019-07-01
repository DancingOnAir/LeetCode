#include <iostream>

using namespace std;

int bulbSwitch(int n)
{
    if (n < 1)
        return 0;

    return sqrt(n);
}

void testBulbSwitch()
{
    cout << bulbSwitch(3) << endl;
}

int main()
{
    testBulbSwitch();
    getchar();
    return 0;
}