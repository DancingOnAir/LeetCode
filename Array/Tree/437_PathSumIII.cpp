#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int helper(TreeNode* root, int target, int sum)
{
    if (nullptr == root)
        return 0;

    sum += root->val;
    //if (target == sum)
    //{
    //    sum -= root->val;
    //    return 1;
    //}

    //helper(root->left, target, sum);
    //helper(root->right, target, sum);
    //sum -= root->val;
    return (sum == target) + helper(root->left, target, sum) + helper(root->right, target, sum);
}

int pathSum(TreeNode* root, int sum)
{
    if (nullptr == root)
        return 0;

    return helper(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

void testPathSum()
{
    TreeNode* node1 = new TreeNode(10);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(-3);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5  = new TreeNode(2);
    TreeNode* node6 = new TreeNode(11);
    TreeNode* node7 = new TreeNode(3);
    TreeNode* node8 = new TreeNode(-2);
    TreeNode* node9 = new TreeNode(1);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;
    node4->left = node7;
    node4->right = node8;
    node5->right = node9;

    int target = 8;
    cout << pathSum(node1, target) << endl;

}

int main()
{
    testPathSum();
    system("pause");
    return 0;
}