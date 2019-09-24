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

vector<int> largestValues2(TreeNode* root)
{
    if (!root)
        return vector<int>();

    vector<int> res;
    TreeNode* pCurrent = nullptr;
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty())
    {
        int len = q.size();
        int maxVal = INT_MIN;
        for (int i = 0; i < len; ++i)
        {
            pCurrent = q.front();
            q.pop();

            maxVal = max(maxVal, pCurrent->val);

            if (pCurrent->left)
                q.emplace(pCurrent->left);
            if (pCurrent->right)
                q.emplace(pCurrent->right);
        }
        res.emplace_back(maxVal);
    }

    return res;
}

void helper(TreeNode* root, int depth, vector<int>& maxs)
{
    if (!root)
        return;

    if (depth >= maxs.size())
    {
        maxs.emplace_back(root->val);
    }
    else
    {
        maxs[depth] = max(maxs[depth], root->val);
    }

    helper(root->left, depth + 1, maxs);
    helper(root->right, depth + 1, maxs);
}

vector<int> largestValues(TreeNode* root)
{
    vector<int> res;
    helper(root, 0, res);

    return res;
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

void display(const vector<int>& nums)
{
    if (nums.empty())
        return;

    for (int x : nums)
        cout << x << ", ";
    cout << endl;
}

void testLargestValues()
{
    vector<string> nums = { "1", "3", "2", "5", "3", "null", "9" };
    auto root = createBinaryTree(nums);
    auto res = largestValues(root);
    display(res);
}

int main()
{
    testLargestValues();

    getchar();
    return 0;
}