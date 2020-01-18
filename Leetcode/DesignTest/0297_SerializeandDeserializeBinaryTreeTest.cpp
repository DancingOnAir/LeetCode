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

TEST_F(CodecTest, checkCodec)
{
    TreeNode* root = codec_->deserialize(codec_->serialize(root_));
    EXPECT_TRUE(root->val == 1);
    EXPECT_TRUE(root->left->val == 2);
    EXPECT_TRUE(root->right->val == 3);
    EXPECT_TRUE(root->left->left == nullptr);
    EXPECT_TRUE(root->left->right == nullptr);
    EXPECT_TRUE(root->right->left->val == 4);
    EXPECT_TRUE(root->right->right->val == 5);
}