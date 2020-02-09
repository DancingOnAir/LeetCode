#include "pch.h"
#include "../SlidingWindow/0438_FindAllAnagramsinaString.h"

class FindAllAnagramsinaString : public testing::Test
{
public:
    Solution solution;
};

TEST_F(FindAllAnagramsinaString, InputPatternIsEmpty)
{
    string s = "cbaebabacd";
    vector<int> expect;

    ASSERT_EQ(solution.findAnagrams(s, ""), expect);
}

TEST_F(FindAllAnagramsinaString, InputThreeCharPattern)
{
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> expect = {0 , 6};

    ASSERT_EQ(solution.findAnagrams(s, p), expect);
}