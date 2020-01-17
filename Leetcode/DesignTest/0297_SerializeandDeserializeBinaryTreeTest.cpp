#include "pch.h"
#include "../Design/0297_SerializeandDeserializeBinaryTree.h"

class CodecTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        codec_ = new Codec();

        root_ = new TreeNode(1);
        TreeNode* node2 = new TreeNode(2);
        TreeNode* node3 = new TreeNode(3);
        TreeNode* node4 = new TreeNode(4);
        TreeNode* node5 = new TreeNode(5);
        root_->left = node2;
        root_->right = node3;
        node3->left = node4;
        node3->right = node5;

        data_ = "[1,2,3,null,null,4,5]";
    }

    virtual void TearDown()
    {
        delete codec_;
    }

protected:
    Codec* codec_;
    TreeNode* root_;
    string data_;
};

TEST_F(CodecTest, checkSerialize)
{
    EXPECT_TRUE(codec_->serialize(root_) == data_);
}

TEST_F(CodecTest, checkDeserialize)
{
    EXPECT_TRUE(codec_->deserialize(data_)->val == 1);
}