#include "pch.h"
#include "../BuyAndSellStock/0188_BestTimetoBuyandSellStockIV.h"

using namespace testing;

class ABestTimetoBuyandSellStockIV : public Test
{
public:
    SolutionIV solution;
};

TEST_F(ABestTimetoBuyandSellStockIV, AnswerThreePrices)
{
    vector<int> prices{ 2, 4, 1 };
    int k = 2;
    int expectMaxProfit = 2;

    ASSERT_EQ(solution.maxProfit(k, prices), expectMaxProfit);
}

TEST_F(ABestTimetoBuyandSellStockIV, AnswerSixPrices)
{
    vector<int> prices{ 3, 2, 6, 5, 0, 3 };
    int k = 2;
    int expectMaxProfit = 7;

    ASSERT_EQ(solution.maxProfit(k, prices), expectMaxProfit);
}
