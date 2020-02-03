#include "pch.h"
#include "../BitManipulation/1310_XORQueriesofaSubarray.h"

TEST(XORQueriesofaSubarray, InputEmptyQuery) {
    Solution solution;

    vector<int> arr1;
    vector<vector<int>> queries1;
    EXPECT_EQ(solution.xorQueries(arr1, queries1), vector<int>());
}

TEST(XORQueriesofaSubarray, InputRegularQueries) {
    Solution solution;

    vector<int> arr1 = {1, 3, 4, 8};
    vector<vector<int>> queries1 = { {0, 1}, {1, 2}, {0, 3}, {3, 3} };
    vector<int> output1 = { 2, 7, 14, 8 };
    EXPECT_EQ(solution.xorQueries(arr1, queries1), output1);
}
