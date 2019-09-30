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

void preorderTraversal(TreeNode* root, string& res)
{
    if (!root)
    {
        res += "()";
        return;
    }
    
    res += "(" + to_string(root->val);
    preorderTraversal(root->left, res);
    preorderTraversal(root->right, res);
    res += ")";
}

string tree2str(TreeNode* t)
{
    if (!t)
        return "";

    string res = to_string(t->val);
    if (t->left)
        res += "(" + tree2str(t->left) + ")";
    else if (t->right)
        res += "()";

    if (t->right)
        res += "(" + tree2str(t->right) + ")";

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

void testTree2str()
{
    vector<string> nums1 = { "1", "2", "3", "4" };
    TreeNode* root1 = createBinaryTree(nums1);
    cout << tree2str(root1) << endl;

    vector<string> nums2 = { "1", "2", "3", "null", "4" };
    TreeNode* root2 = createBinaryTree(nums2);
    cout << tree2str(root2) << endl;
}

int main()
{
    testTree2str();

    getchar();
    return 0;
}