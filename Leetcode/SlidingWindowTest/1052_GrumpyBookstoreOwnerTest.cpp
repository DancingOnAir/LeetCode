#include "pch.h"
#include "../SlidingWindow/1052_GrumpyBookstoreOwner.h"
using namespace testing;

class GrumpyBookstoreOwner : public Test
{
public:
    Solution solution;
};

TEST_F(GrumpyBookstoreOwner, AnswerEmptyCustomers)
{
    vector<int> customers{};
    vector<int> grumpy{};
    int X = 3;

    ASSERT_EQ(solution.maxSatisfied(customers, grumpy, X), 0);
}

TEST_F(GrumpyBookstoreOwner, AnswerCustomersAndGrumpyContain8ElmentsAndXEq3)
{
    vector<int> customers{ 1,0,1,2,1,1,7,5 };
    vector<int> grumpy{ 0,1,0,1,0,1,0,1 };
    int X = 3;

    ASSERT_EQ(solution.maxSatisfied(customers, grumpy, X), 16);
}

TEST_F(GrumpyBookstoreOwner, AnswerCustomersAndGrumpyContain4ElmentsAndXEq1)
{
    vector<int> customers{ 2, 6, 6, 9 };
    vector<int> grumpy{ 0, 0, 1, 1 };
    int X = 1;

    ASSERT_EQ(solution.maxSatisfied(customers, grumpy, X), 17);
}
