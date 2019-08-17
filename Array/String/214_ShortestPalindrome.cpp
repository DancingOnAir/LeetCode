#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string shortestPalindrome(string s)
{
    if (s.empty())
        return "";

    int n = s.size();
    int i = n - 1;
    int maxLen = INT_MIN;
    for (; i > 0; --i)
    {
        int j = i, k = 0;
        for (; j > k; --j, ++k)
        {
            if (s[j] != s[k])
                break;
        }

        if (j <= k)
        {
            break;
        }
    }

    string res = s;
    for (int j = i + 1; j < n; ++j)
    {
        res = s[j] + res;
    }

    return res;
}

void testShortestPalindrome()
{
    string input1 = "aacecaaa";
    cout << shortestPalindrome(input1) << endl;

    string input2 = "abcd";
    cout << shortestPalindrome(input2) << endl;

    string input3 = "abbacd";
    cout << shortestPalindrome(input3) << endl;
}

int main()
{
    testShortestPalindrome();

    getchar();
    return 0;
}