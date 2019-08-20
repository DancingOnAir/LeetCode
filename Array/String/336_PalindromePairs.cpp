#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string& word)
{
    int i = 0, j = word.size() - 1;
    for (; i < j; ++i, --j)
    {
        if (word[i] != word[j])
            return false;
    }

    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words)
{
    vector<vector<int>> res;
    if (words.empty())
        return res;

    for (int i = 0; i < words.size(); ++i)
    {
        for (int j = 0; j < words.size(); ++j)
        {
            if (i == j)
                continue;

            string s = words[i] + words[j];
            if (isPalindrome(s))
            {
                res.emplace_back(vector<int>({i, j}));
            }

        }
    }

    return res;
}

void display(vector<vector<int>> p)
{
    for (auto& r : p)
    {
        for (auto& c : r)
            cout << c << ", ";
        cout << endl;
    }
}

void testPalindromePairs()
{
    vector<string> words1{ "abcd","dcba","lls","s","sssll" };
    auto res1 = palindromePairs(words1);
    display(res1);

    vector<string> words2{ "bat","tab","cat" };
    auto res2 = palindromePairs(words2);
    display(res2);
}

int main()
{

    testPalindromePairs();

    getchar();
    return 0;
}