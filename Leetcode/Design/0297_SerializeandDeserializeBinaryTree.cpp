#include "0297_SerializeandDeserializeBinaryTree.h"
#include <iostream>


void test()
{
    Codec* codec = new Codec();

    auto root = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    root->left = node2;
    root->right = node3;
    node3->left = node4;
    node3->right = node5;

    string res1 = codec->serialize(root);
    cout << res1 << endl;
    string data = "[1,2]";
    TreeNode* res2 = codec->deserialize(data);
}

int main()
{
    test();

    getchar();
    return 0;
}