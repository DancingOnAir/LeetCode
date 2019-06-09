#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b)
{
    string res("");
    if (a.empty() || b.empty())
        return res;

    return res;
}

void testAddBinary()
{
    cout << addBinary("11", "1") << endl;
    cout << addBinary("1010", "1011") << endl;
}

int main()
{
    testAddBinary();
    getchar();
    return 0;
}