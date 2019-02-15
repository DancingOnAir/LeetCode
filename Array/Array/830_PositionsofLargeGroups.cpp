#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> largeGroupPositions(string S)
{
    vector<vector<int>> res;
    vector<int> cur;
    int n = S.size();
    
    if (n < 3)
        return res;

    int count = 1;
    char c = S[0];
    cur.emplace_back(0);
    for (int i = 1; i < n; ++i)
    {
        if (c == S[i])
        {
            ++count;
        }
        else
        {
            if (count >= 3)
            {
                cur.emplace_back(i - 1);
                res.emplace_back(cur);
            }

            c = S[i];
            count = 1;
            cur.clear();
            cur.emplace_back(i);
        }
        
    }

    if (count >= 3)
    {
        cur.emplace_back(n - 1);
        res.emplace_back(cur);
    }

    return res;
}

void testLargeGroupPositions()
{
    string input1 = "abcdddeeeeaabbbcd";
    string input2 = "abc";
    string input3 = "abbxxxxzzy";

    auto res = largeGroupPositions(input1);
    for (auto& row : res)
    {
        for (auto& col : row)
            cout << col << ", ";

        cout << endl;
    }
}

int main()
{
    testLargeGroupPositions();

    getchar();
    return 0;
}