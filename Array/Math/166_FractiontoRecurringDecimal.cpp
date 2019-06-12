#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if (0 == denominator || 0 == numerator)
        return "0";

    string res("");
    if ((denominator > 0) ^ (numerator > 0))
        res += '-';

    long long n = abs((long long)numerator);
    long long d = abs((long long)denominator);
    // append integral part
    res += to_string(n / d);

    if (n % d == 0)
        return res;

    //fractional part
    res += '.';
    unordered_map<int, int> m;
    for (long long r = n % d; r; r %= d)
    {
        if (m.count(r))
        {
            res.insert(m[r], 1, '(');
            res += ')';
            break;
        }

        m[r] = res.size();
        r *= 10;
        res += to_string(r / d);
    }

    return res;
}

void testFractionToDecimal()
{
    cout << fractionToDecimal(1, 2) << endl;
    cout << fractionToDecimal(2, 1) << endl;
    cout << fractionToDecimal(2, 3) << endl;
    cout << fractionToDecimal(INT_MIN, -1) << endl;
}

int main()
{
    testFractionToDecimal();

    getchar();
    return 0;
}