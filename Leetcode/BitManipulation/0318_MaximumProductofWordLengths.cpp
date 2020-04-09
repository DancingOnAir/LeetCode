#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    unsigned int getFingerprint(const string& str)
    {
        if (str.empty())
            return 0;

        int res = 0;
        for (char c : str)
            res |= 1 << (c - 'a');

        return res;
    }

    bool shareNoCommonLetters(string& word1, string& word2)
    {
        int wordBit1 = 0, wordBit2 = 0;
        for (char c : word1)
        {
            wordBit1 |= 1 << (c - 'a');
        }

        for (char c : word2)
        {
            wordBit2 |= 1 << (c - 'a');
        }

        return (wordBit1 & wordBit2) == 0;
    }

    int maxProduct1(vector<string>& words)
    {
        int n = words.size();
        if (n < 2)
            return 0;

        int res = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (shareNoCommonLetters(words[i], words[j]))
                {
                    int temp = words[i].size() * words[j].size();
                    res = max(res, temp);
                }
            }

        }

        return res;
    }

    int maxProduct(vector<string>& words)
    {
        int n = words.size();
        if (n < 2)
            return 0;

        int res = 0;
        vector<int> vec;
        vec.emplace_back(getFingerprint(words[0]));

        for (int i = 1; i < n; ++i)
        {
            int fp = getFingerprint(words[i]);
            for (int j = 0; j < i; ++j)
            {
                if ((fp & vec[j]) == 0)
                {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
            vec.emplace_back(fp);
        }

        return res;
    }
};

void testMaxProduct()
{
    Solution solution;
    std::vector<std::string> words1{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << solution.maxProduct(words1) << endl;

    std::vector<std::string> words2{"a","ab","abc","d","cd","bcd","abcd"};
    cout << solution.maxProduct(words2) << endl;

    std::vector<std::string> words3{"a","aa","aaa","aaaa"};
    cout << solution.maxProduct(words3) << endl;
}

int main()
{
    testMaxProduct();

    return 0;
}