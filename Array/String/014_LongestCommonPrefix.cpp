#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    if (strs.empty())
        return "";

    int n = strs.size();
    if (n == 1)
        return strs[0];

    string res("");
    for (int i = 0; i < strs[0].size(); ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (strs[0][i] != strs[j][i])
            {
                return res;
            }
        }

        res += strs[0][i];
    }

    return res;
}

void testLongestCommonPrefix()
{
    vector<string> strs1{ "flower","flow","flight" };
    cout << longestCommonPrefix(strs1) << endl;

    vector<string> strs2{ "dog","racecar","car" };
    cout << longestCommonPrefix(strs2) << endl;
}

int main()
{
    testLongestCommonPrefix();

    getchar();
    return 0;
}