//#include <iostream>
//#include <vector>
//
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
//void helper(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int sum, int cur)
//{
//    if (nullptr == root)
//        return;
//
//    path.emplace_back(root->val);
//    if (nullptr == root->left && nullptr == root->right)
//    {
//        result.emplace_back(path);
//        path.pop_back();
//        return;
//    }
//
//    helper(root->left, result, path, sum, cur);
//    helper(root->right, result, path, sum, cur);
//    path.pop_back();
//
//}
//
//bool hasPathSum(TreeNode* root, int sum) 
//{
//    if (nullptr == root)
//        return false;
//
//    vector<int> path;
//    vector<vector<int>> result;
//    helper(root, result, path, sum, 0);
//
//    int val = 0;
//    for (auto row : result)
//    {
//        for (auto col : row)
//            val += col;
//
//        if (val == sum)
//            return true;
//
//        val = 0;
//    }
//
//    return false;
//
//}
//
//void testHasPathSum()
//{
//    TreeNode* node1 = new TreeNode(5);
//    TreeNode* node2 = new TreeNode(4);
//    TreeNode* node3 = new TreeNode(8);
//    TreeNode* node4 = new TreeNode(11);
//    TreeNode* node5 = new TreeNode(13);
//    TreeNode* node6 = new TreeNode(4);
//    TreeNode* node7 = new TreeNode(7);
//    TreeNode* node8 = new TreeNode(2);
//    TreeNode* node9 = new TreeNode(1);
//
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node3->left = node5;
//    node3->right = node6;
//    node4->left = node7;
//    node4->right = node8;
//    node6->right = node9;
//
//    auto result = hasPathSum(node1, 22);
//    cout << result << endl;
//}
//
//int main()
//{
//    testHasPathSum();
//    system("pause");
//    return 0;
//}

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

void helper(TreeNode* root, int target, int& val, vector<int>& res)
{
    if (!root->left && !root->right)
    {
        res.emplace_back(val + root->val);
        return;
    }

    val += root->val;
    if (root->left)
        helper(root->left, target, val, res);
    if (root->right)
        helper(root->right, target, val, res);

    val -= root->val;
}

bool hasPathSum(TreeNode* root, int sum)
{
    if (!root)
        return 0 == sum;

    vector<int> res;
    int val = 0;
    helper(root, sum, val, res);

    auto iter = find(res.begin(), res.end(), sum);
    return iter != res.end();
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

void testHasPathSum()
{
    vector<string> nums = { "1", "-2", "-3", "1", "3", "-2", "null", "-1" };
    vector<string> nums2 = { "5", "4", "8", "11", "null", "13", "4", "7", "2", "null", "null", "null", "1" };
    TreeNode* root = createBinaryTree(nums);
    int sum = 22;
    cout << (hasPathSum(root, sum) ? "True" : "False") << endl;
}

int main()
{
    testHasPathSum();

    getchar();
    return 0;
}