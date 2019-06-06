#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;

string multiply(string num1, string num2)
{
    string res = "";
    if ((num1[0] - '0') == 0 || (num2[0] - '0') == 0)
        return "0";
}

void testMultiply()
{
    string num1 = "123";
    string num2 = "456";

    assert(multiply(num1, num2) == "56088");
    cout << multiply(num1, num2) << endl;
}

int main()
{
    testMultiply();

    getchar();
    return 0;
}