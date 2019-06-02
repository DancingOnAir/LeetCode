#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int reverse(int x)
{
    bool isNegative = false;
    if (x < 0)
        isNegative = true;

    string s = to_string(x);

    std::reverse(s.begin(), s.end());
    long long res = isNegative ? -stoll(s) : stoll(s);

    if (res > INT_MAX || res < INT_MIN)
        return 0;

    return static_cast<int>(res);
}

void testReverse()
{
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(120) << endl;
}

int main()
{
    testReverse();
    getchar();
    return 0;
}