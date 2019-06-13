#include <iostream>
#include <string>

using namespace std;

string convertToTitle(int n)
{
    if (n < 1)
        return "";

    string res("");
    int r = 0;
    while (n > 0)
    {
        r = (n - 1) % 26;
        res += r + 'A';

        n = (n - 1) / 26;
    }
    reverse(res.begin(), res.end());

    return res;
}

void testConvertToTitle()
{
    cout << convertToTitle(1) << endl;
    cout << convertToTitle(26) << endl;
    cout << convertToTitle(28) << endl;
    cout << convertToTitle(701) << endl;
}

int main()
{
    testConvertToTitle();

    getchar();
    return 0;
}