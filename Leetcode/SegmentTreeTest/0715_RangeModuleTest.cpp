#include "pch.h"
#include "../SegmentTree/0715_RangeModule.h"
using namespace testing;

class ARangeModule : public Test
{
public:
    RangeModule rangeModule;
};

TEST_F(ARangeModule, AnswerAddRange)
{
    rangeModule.addRange(10, 20);
    rangeModule.removeRange(14, 16);

    EXPECT_TRUE(rangeModule.queryRange(10, 14));
    EXPECT_FALSE(rangeModule.queryRange(13, 15));
    EXPECT_TRUE(rangeModule.queryRange(16, 17));
}
