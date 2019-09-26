#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {

    }
};

void helper(TreeNode* root, TreeNode*& pre)
{
    if (!root)
        return;

    helper(root->right, pre);

    if (pre)
        root->val += pre->val;

    pre = root;

    helper(root->left, pre);
}

TreeNode* convertBST(TreeNode* root)
{
    if (!root)
        return root;

    TreeNode* pre = nullptr;
    helper(root, pre);

    return root;
}

TreeNode* createBinaryTree(const vector<string>& nums)
{
    if (nums.empty())
        return nullptr;

    TreeNode* root = new TreeNode(stoi(nums[0]));
    queue<TreeNode*> q;
    q.emplace(root);
    TreeNode* pCurrent = nullptr;

    int startIndex = 1;
    int nextLevelIndex = 2;
    int restIndex = nums.size() - 1;

    while (restIndex > 0)
    {
        for (int i = startIndex; i < startIndex + nextLevelIndex; i += 2)
        {
            if (i >= nums.size())
                return root;

            pCurrent = q.front();
            q.pop();

            if (nums[i] != "null")
            {
                pCurrent->left = new TreeNode(stoi(nums[i]));
                q.emplace(pCurrent->left);
            }

            if (i + 1 >= nums.size())
                return root;

            if (nums[i + 1] != "null")
            {
                pCurrent->right = new TreeNode(stoi(nums[i + 1]));
                q.emplace(pCurrent->right);
            }
        }

        startIndex += nextLevelIndex;
        restIndex -= nextLevelIndex;
        nextLevelIndex = q.size() * 2;
    }

    return root;
}

void inorderTraversal(TreeNode* root)
{
    if (!root)
        return;

    inorderTraversal(root->left);
    cout << root->val << ", ";
    inorderTraversal(root->right);
}

void testConvertBST()
{
    vector<string> nums = { "5", "2", "13" };
    TreeNode* root = createBinaryTree(nums);
    TreeNode* res = convertBST(root);
    inorderTraversal(res);
}

int main()
{
    testConvertBST();

    getchar();
    return 0;
}