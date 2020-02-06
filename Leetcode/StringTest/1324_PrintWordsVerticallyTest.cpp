#include "pch.h"
#include "../String/1324_PrintWordsVertically.h"
using namespace testing;

class PrintVertically : public Test
{
public:
    Solution solution_;
};

TEST_F(PrintVertically, InputEmptyStringReturnEmpty)
{
    EXPECT_EQ(solution_.printVertically(""), vector<string>());
}

TEST_F(PrintVertically, InputStringWithSameLength)
{
    string s = "HOW ARE YOU";
    vector<string> res = { "HAY","ORO","WEU" };
    EXPECT_EQ(solution_.printVertically(s), res);
}

TEST_F(PrintVertically, InputStringWithDiffLength)
{
    string s = "TO BE OR NOT TO BE";
    vector<string> res = { "TBONTB", "OEROOE", "   T" };
    EXPECT_EQ(solution_.printVertically(s), res);
}
