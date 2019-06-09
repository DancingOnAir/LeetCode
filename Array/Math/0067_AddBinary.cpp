#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b)
{
    if (a.empty() || b.empty())
        return "";

    int l1 = a.size();
    int l2 = b.size();

    if (l1 < l2)
        return addBinary(b, a);

    string res("");
    int carry = 0;
    for (int i = l2 - 1; i >= 0; --i)
    {
        int temp = (a[l1 - l2 + i] - '0') + (b[i] - '0') + carry;
        res = to_string(temp % 2) + res;
        carry = temp / 2;
    }

    for (int i = l1 - l2 - 1; i >= 0; --i)
    {
        int temp = (a[i] - '0') + carry;
        res = to_string(temp % 2) + res;
        carry = temp / 2;
    }

    if (carry == 1)
        res = to_string(carry) + res;

    return res;
}

void testAddBinary()
{
    cout << addBinary("100", "110010") << endl;
    cout << addBinary("11", "1") << endl;
    cout << addBinary("1010", "1011") << endl;
}

int main()
{
    testAddBinary();
    getchar();
    return 0;
}