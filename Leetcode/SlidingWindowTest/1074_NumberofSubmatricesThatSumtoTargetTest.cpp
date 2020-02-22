#include "pch.h"
#include "../SlidingWindow/1074_NumberofSubmatricesThatSumtoTarget.h"

using namespace testing;

class NumberofSubmatricesThatSumtoTarget : public Test
{
public:
    Solution solution;
};

TEST_F(NumberofSubmatricesThatSumtoTarget, Answer3x3MatrixAndTargetEq0)
{
    vector<vector<int>> matrix{ {0, 1, 0},{1, 1, 1},{0, 1, 0} };
    int target = 0;

    ASSERT_EQ(solution.numSubmatrixSumTarget(matrix, target), 4);
}

TEST_F(NumberofSubmatricesThatSumtoTarget, Answer2x2MatrixAndTargetEq0)
{
    vector<vector<int>> matrix{ {1, -1},{-1, 1} };
    int target = 0;

    ASSERT_EQ(solution.numSubmatrixSumTarget(matrix, target), 5);
}
