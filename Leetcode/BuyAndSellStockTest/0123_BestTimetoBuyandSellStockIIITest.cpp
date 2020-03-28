#include "pch.h"
#include "../BuyAndSellStock/0123_BestTimetoBuyandSellStockIII.h"
using namespace testing;

class ABestTimetoBuyandSellStockIII : public Test
{
public:
    SolutionIII solution;
};

TEST_F(ABestTimetoBuyandSellStockIII, AnswerEmptyPrices)
{
    vector<int> emptyPrices{};
    int maxProfit = 0;

    ASSERT_EQ(solution.maxProfit(emptyPrices), maxProfit);
}

TEST_F(ABestTimetoBuyandSellStockIII, AnswerEightPrices)
{
    vector<int> prices{ 3, 3, 5, 0, 0, 3, 1, 4 };
    int maxProfit = 6;

    ASSERT_EQ(solution.maxProfit(prices), maxProfit);
}

TEST_F(ABestTimetoBuyandSellStockIII, AnswerAscendingFivePrices)
{
    vector<int> prices{ 1, 2, 3, 4, 5 };
    int maxProfit = 4;

    ASSERT_EQ(solution.maxProfit(prices), maxProfit);
}

TEST_F(ABestTimetoBuyandSellStockIII, AnswerDescendingFivePrices)
{
    vector<int> prices{ 7, 6, 4, 3, 1 };
    int maxProfit = 0;

    ASSERT_EQ(solution.maxProfit(prices), maxProfit);
}
