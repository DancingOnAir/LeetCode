#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string intToRoman(int num)
{
    string res("");
    if (num < 1 || num > 3999)
        return res;

    vector<string> symbols{"I", "V", "X", "L", "C", "D", "M"};
    int flag = 0;
    while (num != 0)
    {

        int pop = num % 10;

        string temp("");
        if (pop < 4)
        {
            temp = string(pop, symbols[2 * flag][0]);
        }
        else if (pop == 4)
        {
            temp = symbols[2 * flag] + symbols[2 * flag + 1];
        }
        else if (pop == 5)
        {
            temp = symbols[2 * flag + 1];
        }
        else if (pop < 9)
        {
            temp = symbols[2 * flag + 1] + string(pop - 5, symbols[2 * flag][0]);
        }
        else
        {
            temp = symbols[2 * flag] + symbols[2 * flag + 2];
        }

        res = temp + res;
        num /= 10;
        ++flag;
    }

    return res;
}

void testIntToRoman()
{
    cout << intToRoman(3) << endl;
    cout << intToRoman(4) << endl;
    cout << intToRoman(9) << endl;
    cout << intToRoman(58) << endl;
    cout << intToRoman(1994) << endl;
}

int main()
{
    testIntToRoman();

    getchar();
    return 0;
}