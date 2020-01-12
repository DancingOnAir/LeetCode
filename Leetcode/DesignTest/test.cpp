#include "pch.h"
#include "../Design/0211_AddandSearchWord.h"

TEST(AddandSearchWordTest, searchNormalWord)
{
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");

    EXPECT_FALSE(wordDictionary.search("pad"));
    EXPECT_TRUE(wordDictionary.search("bad"));
}

TEST(AddandSearchWordTest, searchTokenWord)
{
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");

    EXPECT_TRUE(wordDictionary.search(".ad"));
    EXPECT_TRUE(wordDictionary.search("b.."));
}