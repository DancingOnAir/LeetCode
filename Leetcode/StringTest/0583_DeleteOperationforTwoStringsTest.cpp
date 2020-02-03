#include "pch.h"
#include "../String/0583_DeleteOperationforTwoStrings.h"

TEST(DeleteOperationforTwoStrings, CompareEmptyWords) {
    Solution solution;

    EXPECT_EQ(solution.minDistance("", ""), 0);
}

TEST(DeleteOperationforTwoStrings, CompareWithOnlyOneEmptyWord) {
    Solution solution;

    string word1 = "abcd";
    string word2 = "";
    EXPECT_EQ(solution.minDistance(word1, word2), 4);
}

TEST(DeleteOperationforTwoStrings, CompareWithTwoRegularWord) {
    Solution solution;

    string word1 = "sea";
    string word2 = "eat";
    EXPECT_EQ(solution.minDistance(word1, word2), 2);
}

TEST(DeleteOperationforTwoStrings, CompareWithTwoSingleChar) {
    Solution solution;

    string word1 = "a";
    string word2 = "b";
    EXPECT_EQ(solution.minDistance(word1, word2), 2);
}