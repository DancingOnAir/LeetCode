#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void helper(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int sum, int cur)
{
    if (nullptr == root)
        return;

    path.emplace_back(root->val);
    if (nullptr == root->left && nullptr == root->right)
    {
        result.emplace_back(path);
        path.pop_back();
        return;
    }

    helper(root->left, result, path, sum, cur);
    helper(root->right, result, path, sum, cur);
    path.pop_back();

}

bool hasPathSum(TreeNode* root, int sum) 
{
    if (nullptr == root)
        return false;

    vector<int> path;
    vector<vector<int>> result;
    helper(root, result, path, sum, 0);

    int val = 0;
    for (auto row : result)
    {
        for (auto col : row)
            val += col;

        if (val == sum)
            return true;

        val = 0;
    }

    return false;

}

void testHasPathSum()
{
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(11);
    TreeNode* node5 = new TreeNode(13);
    TreeNode* node6 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(2);
    TreeNode* node9 = new TreeNode(1);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node5;
    node3->right = node6;
    node4->left = node7;
    node4->right = node8;
    node6->right = node9;

    auto result = hasPathSum(node1, 22);
    cout << result << endl;
}

int main()
{
    testHasPathSum();
    system("pause");
    return 0;
}