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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if (!t1 || !t2)
        return t1 ? t1 : t2;

    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
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

void preorderTraversal(TreeNode* root)
{
    if (!root)
        return;

    cout << root->val << ", ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void testMergeTrees()
{
    vector<string> nums1 = { "1", "3", "2", "5" };
    vector<string> nums2 = { "2", "1", "3", "null", "4", "null", "7" };
    TreeNode* root1 = createBinaryTree(nums1);
    TreeNode* root2 = createBinaryTree(nums2);

    TreeNode* res1 = mergeTrees(root1, root2);
    preorderTraversal(res1);
}

int main()
{
    testMergeTrees();

    getchar();
    return 0;
}