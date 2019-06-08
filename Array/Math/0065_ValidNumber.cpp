#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

bool isNumber(string s)
{
    int n = s.size();
    if (0 == n)
        return false;

    int i = 0;
    int countNum = 0, countPoint = 0;
    while (s[i] == ' ')
        ++i;

    if (s[i] == '+' || s[i] == '-')
        ++i;

    while (isdigit(s[i]) || s[i] == '.')
        s[i++] == '.' ? countPoint++ : countNum++;

    if (countPoint > 1 || countNum < 1)
        return false;

    if (s[i] == 'e')
    {
        ++i;
        countNum = 0;
        countPoint = 0;
        if (s[i] == '+' || s[i] == '-')
            ++i;

        while (isdigit(s[i]) || s[i] == '.')
            s[i++] == '.' ? countPoint++ : countNum++;

        if (countPoint > 0 || countNum < 1)
            return false;
    }

    while (s[i] == ' ')
        ++i;

    return n == i;
}

void testIsNumber()
{
    //assert(isNumber(".1") == true);
    //assert(isNumber("0") == true);
    //assert(isNumber("0.1") == true);
    //assert(isNumber("abc") == false);
    //assert(isNumber("1 a") == false);
    //assert(isNumber("2e10") == true);
    assert(isNumber(" -90e3   ") == true);
    assert(isNumber(" 1e") == false);
    assert(isNumber("e3") == false);
    assert(isNumber(" 6e-1") == true);
    assert(isNumber(" 99e2.5") == false);
    assert(isNumber("53.5e93") == true);
    assert(isNumber(" --6") == false);
    assert(isNumber("-+3") == false);
    assert(isNumber("95a54e53") == false);

    return;
}

int main()
{
    testIsNumber();

    getchar();
    return 0;
}