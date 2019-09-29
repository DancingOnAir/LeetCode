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

bool isSameTree(TreeNode* s, TreeNode* t)
{
    if (!s || !t)
        return s == t;

    return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t)
{
    if (!s || !t)
        return s == t;

    queue<TreeNode*> q;
    q.emplace(s);
    TreeNode* pCurrent = nullptr;

    while (!q.empty())
    {
        int len = q.size();

        for (int i = 0; i < len; ++i)
        {
            pCurrent = q.front();
            q.pop();

            if (pCurrent->val == t->val)
            {
                if (isSameTree(pCurrent, t))
                    return true;
            }

            if (pCurrent->left)
                q.emplace(pCurrent->left);
            if (pCurrent->right)
                q.emplace(pCurrent->right);
        }
    }

    return false;
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

void testIsSubtree()
{
    vector<string> nums1 = { "3", "4", "5", "1", "2", "null", "null", "null", "null", "0" };
    vector<string> nums2 = { "4", "1", "2" };

    TreeNode* root1 = createBinaryTree(nums1);
    TreeNode* root2 = createBinaryTree(nums2);
    cout << (isSubtree(root1, root2) ? "True" : "False") << endl;
}

int main()
{
    testIsSubtree();

    getchar();
    return 0;
}