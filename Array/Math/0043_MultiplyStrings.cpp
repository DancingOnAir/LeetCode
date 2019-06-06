#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;

string multiply(string num1, string num2)
{
    int l1 = num1.size();
    int l2 = num2.size();

    string sum(l1 + l2, '0');
    for (int i = l1 - 1; i >= 0; --i)
    {
        int carry = 0;
        for (int j = l2 - 1; j >= 0; --j)
        {
            int temp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = temp % 10 + '0';
            carry = temp / 10;
        }
        sum[i] += carry;
    }

    size_t pos = sum.find_first_not_of("0");
    if (pos != string::npos)
        return sum.substr(pos);

    return "0";
}

void testMultiply()
{
    string num1 = "123";
    string num2 = "456";

    //assert(multiply(num1, num2) == "56088");
    cout << multiply(num1, num2) << endl;
}

int main()
{
    testMultiply();

    getchar();
    return 0;
}