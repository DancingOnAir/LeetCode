#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(string s, int numRows)
{
    int n = s.size();
    if (n < 2 || numRows < 2)
        return s;

    int k = 2 * numRows - 2;
    vector<string> res(numRows, "");
    for (int i = 0; i < n; ++i)
    {
        int remainder = i % k;

        if (remainder > numRows - 1)
            remainder = k - remainder;

        res[remainder] += s[i];
    }

    string ans;
    for (string& str : res)
        ans += str;

    return ans;
}

void testConvert()
{
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << convert(s1, numRows1) << endl;

    int numRows2 = 4;
    cout << convert(s1, numRows2) << endl;
}

int main()
{
    testConvert();

    getchar();
    return 0;
}