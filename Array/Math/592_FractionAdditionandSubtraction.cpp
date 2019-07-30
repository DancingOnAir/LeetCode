#include <iostream>
#include <string>

using namespace std;

string fractionAddition(string expression)
{
    if (expression.empty())
        return "";

    string res("");
    return res;
}

void testFractionAddtion()
{
    string expression1 = "-1/2+1/2";
    cout << fractionAddition(expression1) << endl;

    string expression2 = "-1/2+1/2+1/3";
    cout << fractionAddition(expression2) << endl;

    string expression3 = "1/3-1/2";
    cout << fractionAddition(expression3) << endl;

    string expression3 = "5/3+1/3";
    cout << fractionAddition(expression3) << endl;
}

int main()
{
    testFractionAddtion();

    getchar();
    return 0;
}