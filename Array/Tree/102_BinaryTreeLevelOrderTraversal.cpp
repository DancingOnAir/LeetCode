#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    if (nullptr == root)
        return result;

    queue<TreeNode *> q;
    q.push(root);
    vector<int> curLevel;
    TreeNode* curNode = nullptr;

    while (!q.empty())
    {
        int l = q.size();
        for (auto i = 0; i < l; ++i)
        {
            curNode = q.front();
            curLevel.push_back(curNode->val);
            q.pop();

            if (curNode->left)
                q.push(curNode->left);
            if (curNode->right)
                q.push(curNode->right);
        }

        result.push_back(curLevel);
        curLevel.clear();
    }

    return result;
}

void display(vector<vector<int>>& nums)
{
    if (nums.empty())
        return;

    for (auto row : nums)
    {
        for (auto col : row)
            cout << col << ", ";

        cout << endl;
    }
}

void testLevelOrder()
{
    TreeNode* node1 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(0);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(9);
    TreeNode* node8 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;

    vector<vector<int>> result = levelOrder(node1);
    display(result);
}

int main()
{
    testLevelOrder();

    system("pause");
    return 0;
}