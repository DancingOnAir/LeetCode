#include "pch.h"
#include "../BuyAndSellStock/0121_BestTimetoBuyandSellStock.h"
using namespace testing;

class ABestTimetoBuyandSellStock : public Test
{
public:
    Solution solution;
};

TEST_F(ABestTimetoBuyandSellStock, AnswerEmptyPrices)
{
    vector<int> prices{ };
    int expectMaxProfit = 0;
    ASSERT_EQ(solution.maxProfit(prices), expectMaxProfit);
}

TEST_F(ABestTimetoBuyandSellStock, AnswerFivePrices)
{
    vector<int> prices{ 7, 1, 5, 3, 6, 4 };
    int expectMaxProfit = 5;
    ASSERT_EQ(solution.maxProfit(prices), expectMaxProfit);
}

TEST_F(ABestTimetoBuyandSellStock, AnswerFourPrices)
{
    vector<int> prices{ 7, 6, 4, 3, 1 };
    int expectMaxProfit = 0;
    ASSERT_EQ(solution.maxProfit(prices), expectMaxProfit);
}