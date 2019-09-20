//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//int getDepth(TreeNode* root)
//{
//    if (nullptr == root)
//        return 0;
//
//    return max(getDepth(root->left), getDepth(root->right)) + 1;
//}
//
//bool isBalanced(TreeNode* root)
//{
//    if (nullptr == root)
//        return true;
//
//    return isBalanced(root->left) && isBalanced(root->right) && abs(getDepth(root->left) - getDepth(root->right)) <= 1;
//}
//
//void testMaxDepth()
//{
//    TreeNode* node1 = new TreeNode(3);
//    TreeNode* node2 = new TreeNode(9);
//    TreeNode* node3 = new TreeNode(20);
//    TreeNode* node4 = new TreeNode(15);
//    TreeNode* node5 = new TreeNode(7);
//
//    node1->left = node2;
//    node1->right = node3;
//    node3->left = node4;
//    node3->right = node5;
//
//    cout << isBalanced(node1) << endl;
//}
//
//int main()
//{
//    testMaxDepth();
//    system("pause");
//    return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
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

int maxDepth(TreeNode* root)
{
    if (!root)
        return 0;

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int getHeight(TreeNode* root)
{
    if (!root)
        return 0;

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;

    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) 
{
    if (!root)
        return true;

    return getHeight(root) != -1;
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

void testIsBalanced()
{
    vector<string> nums1 = { "3", "9", "20", "null", "null", "15", "7" };
    TreeNode* root1 = createBinaryTree(nums1);
    cout << (isBalanced(root1) ? "True" : "False") << endl;

    vector<string> nums2 = { "1", "2", "2", "3","3", "null", "null", "4", "4" };
    TreeNode* root2 = createBinaryTree(nums2);
    cout << (isBalanced(root2) ? "True" : "False") << endl;
}

int main()
{
    testIsBalanced();

    getchar();
    return 0;
}