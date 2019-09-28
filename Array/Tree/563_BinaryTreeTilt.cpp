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

int postorderTraversal(TreeNode* root, int& tilt)
{
    if (!root)
        return 0;

    int left = postorderTraversal(root->left, tilt);
    int right = postorderTraversal(root->right, tilt);

    tilt += abs(left - right);

    return root->val + left + right;
}

int findTilt(TreeNode* root)
{
    if (!root)
        return 0;

    int tilt = 0;
    postorderTraversal(root, tilt);

    return tilt;
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

void testFindTilt()
{
    vector<string> nums = { "1", "2", "3", "4", "5", "6" };
    TreeNode* root = createBinaryTree(nums);
    cout << findTilt(root) << endl;
}

int main()
{
    testFindTilt();

    getchar();
    return 0;
}