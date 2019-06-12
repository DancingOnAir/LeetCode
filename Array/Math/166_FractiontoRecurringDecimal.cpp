#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if (0 == denominator || 0 == numerator)
        return 0;


}

void testFractionToDecimal()
{
    cout << fractionToDecimal(1, 2) << endl;
    cout << fractionToDecimal(2, 1) << endl;
    cout << fractionToDecimal(2, 3) << endl;
}

int main()
{
    testFractionToDecimal();

    getchar();
    return 0;
}