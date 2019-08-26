#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2)
{
    int d1 = 0, d2 = 0, additional = 0;
    string res;
    while (!num1.empty() || !num2.empty() || additional)
    {
        if (num1.empty())
            d1 = 0;
        else
        {
            
            d1 = num1.back() - '0';
            num1.pop_back();
        }

        if (num2.empty())
            d2 = 0;
        else
        {
            d2 = num2.back() - '0';
            num2.pop_back();
        }

        int digit = (d1 + d2 + additional) % 10;
        additional = (d1 + d2 + additional) / 10;
        res = to_string(digit) + res;
    }

    return res;
}

void testAddStrings()
{
    cout << addStrings("12", "988") << endl;
}

int main()
{
    testAddStrings();

    getchar();
    return 0;
}