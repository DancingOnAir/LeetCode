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

int depthOfBinaryTree2(TreeNode* root)
{
    if (!root)
        return 0;

    return max(depthOfBinaryTree2(root->left), depthOfBinaryTree2(root->right)) + 1;
}

void preorderTraversal(TreeNode* root, int& maxVal)
{
    if (!root)
        return;

    maxVal = max(maxVal, depthOfBinaryTree2(root->left) + depthOfBinaryTree2(root->right));
    preorderTraversal(root->left, maxVal);
    preorderTraversal(root->right, maxVal);
}

int diameterOfBinaryTree2(TreeNode* root)
{
    if (!root)
        return 0;

    int maxVal = INT_MIN;
    preorderTraversal(root, maxVal);

    return maxVal;
}

int maxVal = INT_MIN;

int depthOfBinaryTree(TreeNode* root)
{
    if (!root)
        return 0;

    maxVal = max(maxVal, depthOfBinaryTree(root->left) + depthOfBinaryTree(root->right));
    return max(depthOfBinaryTree(root->left), depthOfBinaryTree(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    if (!root)
        return 0;

    depthOfBinaryTree(root);

    return maxVal;
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

void testDiameterOfBinaryTree()
{
    vector<string> nums1 = { "1", "2", "3", "4", "5" };
    TreeNode* root1 = createBinaryTree(nums1);
    cout << diameterOfBinaryTree(root1) << endl;
}

int main()
{
    testDiameterOfBinaryTree();

    getchar();
    return 0;
}