#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool isSequentialString(string& rhs)
{
    if (rhs.size() < 2)
        return true;

    for (int i = 0; i < rhs.size() - 1; ++i)
    {
        if ((rhs[i] - 'a' + 1) % 26 != (rhs[i + 1] - 'a') % 26)
        {
            return false;
        }
    }

    return true;
}

int findSubstringInWraproundString(string p)
{
    if (p.empty())
        return 0;

    int res = 0;
    int n = p.size();
    unordered_set<string> s;
    string tempStr("");

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < n - i + 1; ++j)
        {
            tempStr = p.substr(j, i);
            if (isSequentialString(tempStr))
            {
                s.emplace(tempStr);
            }
        }

        res += s.size();
        s.clear();
    }
    
    return res;
}

int findSubstringInWraproundString2(string p)
{
    if (p.empty())
        return 0;

    vector<int> count(26);
    int maxLength = 0;

    for (int i = 0; i < p.size(); ++i)
    {
        if (i > 0 && ((p[i] - p[i - 1] == 1) || (p[i - 1] - p[i] == 25)))
        {
            ++maxLength;
        }
        else
        {
            maxLength = 1;
        }

        int index = p[i] - 'a';
        count[index] = max(count[index], maxLength);
    }

    int sum = 0;
    for (int i = 0; i < 26; ++i)
    {
        sum += count[i];
    }

    return sum;
}

void testFindSubstringInWraproundString()
{
    string input = "cac";
    cout << findSubstringInWraproundString2(input) << endl;
}

int main()
{
    testFindSubstringInWraproundString();

    getchar();
    return 0;
}