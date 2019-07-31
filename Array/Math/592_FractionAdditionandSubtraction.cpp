#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gcd(int lhs, int rhs)
{
    return rhs == 0 ? lhs : gcd(rhs, lhs % rhs);
}

int lcm(int lhs, int rhs)
{
    return lhs * rhs / gcd(lhs, rhs);
}

string fractionAddition(string expression)
{
    if (expression.empty())
        return "";

    string res("");


    vector<int> denominators;
    vector<int> numerators;
    vector<int> nums;
    int n = expression.size();
    int idx = 0;
    string temp("");

    while (idx < n)
    {
        int len = 1;
        for (; expression[idx + len - 1] != '/'; ++len)
        {
            ;
        }

        temp = expression.substr(idx, len - 1);
        numerators.emplace_back(stoi(temp));

        idx += len;


        len = 1;
        for (; expression[idx + len - 1] >= '0' &&  expression[idx + len - 1] <= '9'; ++len)
        {

        }

        temp = expression.substr(idx, len - 1);
        denominators.emplace_back(stoi(temp));
        idx += len - 1;
    }

    int m = numerators.size();
    if (m == 1)
        return expression;

    int denominator = 1;
    for (int i = 0; i < m; ++i)
    {
        denominator = lcm(denominator, denominators[i]);
    }

    int numerator = 0;
    for (int i = 0; i < m; ++i)
    {
        numerator += numerators[i] * denominator / denominators[i];
    }

    //if (denominator == 0 || numerator == 0)
    //    return to_string(numerator) + '/' + to_string(denominator);

    int tempGCD = gcd(abs(denominator), abs(numerator));
    numerator /= tempGCD;
    denominator /= tempGCD;
    return to_string(numerator) + '/' + to_string(denominator);
}

void testFractionAddtion()
{
    string expression1 = "-1/2+1/2";
    cout << fractionAddition(expression1) << endl;

    string expression2 = "-1/2+1/2+1/3";
    cout << fractionAddition(expression2) << endl;

    string expression3 = "1/3-1/2";
    cout << fractionAddition(expression3) << endl;

    string expression4 = "5/3+1/3";
    cout << fractionAddition(expression4) << endl;
}

int main()
{
    testFractionAddtion();

    getchar();
    return 0;
}