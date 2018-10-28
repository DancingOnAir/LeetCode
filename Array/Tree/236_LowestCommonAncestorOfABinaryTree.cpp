#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (nullptr == root || nullptr == p || nullptr == q)
        return nullptr;

    if (root == p || root == q)
        return root;

    auto l = lowestCommonAncestor(root->left, p, q);
    auto r = lowestCommonAncestor(root->right, p, q);

    if (l && r)
        return root;

    return l != nullptr ? l : r;
}

void testLowestCommonAncestor()
{
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(0);
    TreeNode* node7 = new TreeNode(8);
    TreeNode* node8 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(4);
    
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;

    auto result = lowestCommonAncestor(node1, node2, node3);
    std::cout << result->val << std::endl;
}

int main()
{
    testLowestCommonAncestor();
    system("pause");
    return 0;
}