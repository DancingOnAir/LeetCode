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

int minDepth2(TreeNode* root)
{
    if (!root)
        return 0;

    TreeNode* pCurrent = nullptr;
    queue<TreeNode*> q;
    q.emplace(root);
    int res = 0;

    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; ++i)
        {
            pCurrent = q.front();
            q.pop();
            if (pCurrent->left)
                q.emplace(pCurrent->left);
            if (pCurrent->right)
                q.emplace(pCurrent->right);

            if (!pCurrent->left && !pCurrent->right)
                return res + 1;
        }

        ++res;
    }

    return res;
}

int minDepth(TreeNode* root)
{
    if (!root)
        return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    return (min(left, right) ? min(left, right) : max(left, right)) + 1;
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

void testMinDepth()
{
    vector<string> nums = { "3","9","20","null","null","15","7" };
    TreeNode* root = createBinaryTree(nums);
    cout << minDepth(root) << endl;
}

int main()
{
    testMinDepth();

    getchar();
    return 0;
}