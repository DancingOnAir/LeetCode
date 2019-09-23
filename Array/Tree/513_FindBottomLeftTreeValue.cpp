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

int findBottomLeftValue(TreeNode* root)
{
    if (!root)
        return 0;

    TreeNode* pCurrent = nullptr;
    queue<TreeNode*> q;
    q.emplace(root);
    vector<int> res;

    while (!q.empty())
    {
        int len = q.size();
        res.clear();
        for (int i = 0; i < len; ++i)
        {
            pCurrent = q.front();
            q.pop();
            res.emplace_back(pCurrent->val);

            if (pCurrent->left)
                q.emplace(pCurrent->left);
            if (pCurrent->right)
                q.emplace(pCurrent->right);
        }
    }

    return res[0];
}

int findBottomLeftValue2(TreeNode* root)
{
    queue<TreeNode*> q;
    q.emplace(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        if (root->right)
            q.emplace(root->right);
        if (root->left)
            q.emplace(root->left);
    }

    return root->val;
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

void testFindBottomLeftValue()
{
    //vector<string> nums1 = { "2", "1", "3" };
    //TreeNode* root1 = createBinaryTree(nums1);
    //cout << findBottomLeftValue(root1) << endl;

    vector<string> nums2 = { "1", "2", "3", "4", "null", "5", "6", "null", "null", "7" };
    TreeNode* root2 = createBinaryTree(nums2);
    cout << findBottomLeftValue(root2) << endl;
}

int main()
{
    testFindBottomLeftValue();

    getchar();
    return 0;
}