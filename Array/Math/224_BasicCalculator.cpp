#include <iostream>
#include <string>
#include <stack>
using namespace std;

int calculate(string s)
{
    stack<int> signs;
    int num = 0, res = 0, sign = 1;
    signs.emplace(sign);
    for (char c : s)
    {
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        else if (c == '(')
            signs.emplace(sign);
        else if (c == ')')
            signs.pop();
        else if (c == '+' || c == '-')
        {
            res += sign * num;
            num = 0;
            sign = signs.top() * (c == '+' ? 1 : -1);
        }
    }

    return res + sign * num;
}

void testCalculate()
{
    cout << calculate("2-(5-6)") << endl;
    cout << calculate("1-1") << endl;
    cout << calculate("123 + 45") << endl;
    cout << calculate("1 + 1") << endl;
    cout << calculate("2-1 + 2") << endl;
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
}

int main()
{
    testCalculate();

    getchar();
    return 0;
}