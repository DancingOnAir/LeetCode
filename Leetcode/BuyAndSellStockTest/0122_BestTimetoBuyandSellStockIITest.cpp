#include "pch.h"
#include "../BuyAndSellStock/0122_BestTimetoBuyandSellStockII.h"
using namespace testing;

class ABestTimetoBuyandSellStockII : public Test
{
public:
    SolutionII solution;
};

TEST_F(ABestTimetoBuyandSellStockII, AnswerSixPrices)
{
    vector<int> prices{ 7, 1, 5, 3, 6, 4 };
    int expectMaxProfit = 7;
    ASSERT_EQ(solution.maxProfit(prices), expectMaxProfit);
}

TEST_F(ABestTimetoBuyandSellStockII, AnswerFivePricesI)
{
    vector<int> prices{ 1, 2, 3, 4, 5 };
    int expectMaxProfit = 4;
    ASSERT_EQ(solution.maxProfit(prices), expectMaxProfit);
}

TEST_F(ABestTimetoBuyandSellStockII, AnswerFivePricesII)
{
    vector<int> prices{ 7, 6, 4, 3, 1 };
    int expectMaxProfit = 0;
    ASSERT_EQ(solution.maxProfit(prices), expectMaxProfit);
}