#include "pch.h"
#include "../BuyAndSellStock/0714_BestTimetoBuyandSellStockwithTransactionFee.h"
using namespace testing;

class ABestTimetoBuyandSellStockwithTransactionFee : public Test
{
public:
    SolutionVI solution;
};

TEST_F(ABestTimetoBuyandSellStockwithTransactionFee, AnswerEmptyPrices)
{
    vector<int> prices{};
    int maxProfit = 0;
    int fee = 1;

    ASSERT_EQ(solution.maxProfit(prices, fee), maxProfit);
}

TEST_F(ABestTimetoBuyandSellStockwithTransactionFee, AnswerSixPrices)
{
    vector<int> prices{ 1, 3, 2, 8, 4, 9 };
    int maxProfit = 8;
    int fee = 2;

    ASSERT_EQ(solution.maxProfit(prices, fee), maxProfit);
}
