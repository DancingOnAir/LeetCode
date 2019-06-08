#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

bool isNumber(string s)
{
    if (s.empty())
        return false;

    return true;
}

void testIsNumber()
{
    assert(isNumber("0") == true);
    assert(isNumber("0.1") == true);
    assert(isNumber("abc") == false);
    assert(isNumber("1 a") == false);
    assert(isNumber("2e10") == true);
    assert(isNumber(" -90e3   ") == true);
    assert(isNumber(" 1e") == false);
    assert(isNumber("e3") == false);
    assert(isNumber(" 6e-1") == true);
    assert(isNumber(" 99e2.5") == false);
    assert(isNumber("53.5e93") == true);
    assert(isNumber(" --6") == false);
    assert(isNumber("-+3") == false);
    assert(isNumber("95a54e53") == false);
}

int main()
{
    testIsNumber();

    getchar();
    return 0;
}