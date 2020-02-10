#include "pch.h"
#include "../SlidingWindow/0030_SubstringwithConcatenationofAllWords.h"
#include <algorithm>

class SubstringwithConcatenationofAllWords : public testing::Test
{
public:
    Solution solution;

    vector<int> SortResult(vector<int>& indice)
    {
        sort(indice.begin(), indice.end());
        return indice;
    }
};

TEST_F(SubstringwithConcatenationofAllWords, InputEmptyString)
{
    string s = "";
    vector<string> words = { "foo","bar" };

    ASSERT_EQ(solution.findSubstring(s, words), vector<int>());
}

TEST_F(SubstringwithConcatenationofAllWords, InputStringContainsAvailableSubstring)
{
    string s = "barfoothefoobarman";
    vector<string> words = { "foo","bar" };
    vector<int> expect = { 0, 9 };

    ASSERT_EQ(solution.findSubstring(s, words), expect);
}

TEST_F(SubstringwithConcatenationofAllWords, InputStringContainsInAvailableSubstring)
{
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = { "word", "good", "best", "word" };

    ASSERT_EQ(solution.findSubstring(s, words), vector<int>());
}

TEST_F(SubstringwithConcatenationofAllWords, InputStringContainsAvailableSubstringWithTrashHeader)
{
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = { "fooo", "barr", "wing", "ding", "wing" };
    vector<int> expect = { 13 };

    ASSERT_EQ(solution.findSubstring(s, words), expect);
}

TEST_F(SubstringwithConcatenationofAllWords, InputStringContainsAvailableSubstringWithSameChars)
{
    string s = "aaaaaaaa";
    vector<string> words = { "aa", "aa", "aa" };
    vector<int> expect = { 0, 1, 2 };

    ASSERT_EQ(SortResult(solution.findSubstring(s, words)), expect);
}