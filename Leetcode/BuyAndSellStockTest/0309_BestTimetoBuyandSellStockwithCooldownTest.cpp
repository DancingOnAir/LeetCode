#include "pch.h"
#include "../BuyAndSellStock/0309_BestTimetoBuyandSellStockwithCooldown.h"

using namespace testing;

class ABestTimetoBuyandSellStockwithCooldown : public Test
{
public:
    SolutionV solution;
};

TEST_F(ABestTimetoBuyandSellStockwithCooldown, AnswerEmptyPrices)
{
    vector<int> prices{};
    int maxProfit = 0;

    ASSERT_EQ(solution.maxProfit(prices), maxProfit);
}

TEST_F(ABestTimetoBuyandSellStockwithCooldown, AnswerFivePrices)
{
    vector<int> prices{ 1, 2, 3, 0, 2 };
    int maxProfit = 3;

    ASSERT_EQ(solution.maxProfit(prices), maxProfit);
}