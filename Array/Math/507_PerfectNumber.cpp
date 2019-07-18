#include <iostream>

using namespace std;

bool checkPerfectNumber(int num)
{
    if (num < 2)
        return false;

    int rest = num;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            rest -= (i + num / i);
    }

    return 1 == rest;
}

void testCheckPerfectNumber()
{
    cout << (checkPerfectNumber(6) ? "T" : "F") << endl;
    cout << (checkPerfectNumber(28) ? "T" : "F") << endl;
    cout << (checkPerfectNumber(30) ? "T" : "F") << endl;
    cout << (checkPerfectNumber(100000000) ? "T" : "F") << endl;
}

int main()
{
    testCheckPerfectNumber();
    getchar();
    return 0;
}