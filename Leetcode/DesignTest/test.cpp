#include "pch.h"
#include "../Design/0211_AddandSearchWord.h"

class WordDictionaryTest: public testing::Test
{
public:
    virtual void SetUp()
    {
        wordDictionary_ = new WordDictionary();
        wordDictionary_->addWord("bad");
        wordDictionary_->addWord("dad");
        wordDictionary_->addWord("mad");
    }

    void TearDown()
    {
        if (!wordDictionary_)
        {
            delete wordDictionary_;
            wordDictionary_ = nullptr;
        }
    }

protected:
    WordDictionary* wordDictionary_;
};

TEST_F(WordDictionaryTest, addWord)
{
    ASSERT_TRUE(wordDictionary_->getRoot()->children[0] == nullptr);
    ASSERT_TRUE(wordDictionary_->getRoot()->children['b' - 'a'] != nullptr);
    ASSERT_TRUE(wordDictionary_->getRoot()->children['d' - 'a'] != nullptr);
    ASSERT_TRUE(wordDictionary_->getRoot()->children['m' - 'a'] != nullptr);
}

TEST_F(WordDictionaryTest, searchNormalWord)
{
    EXPECT_FALSE(wordDictionary_->search("pad"));
    EXPECT_TRUE(wordDictionary_->search("bad"));
}

TEST_F(WordDictionaryTest, searchTokenWord)
{
    EXPECT_TRUE(wordDictionary_->search(".ad"));
    EXPECT_TRUE(wordDictionary_->search("b.."));
}