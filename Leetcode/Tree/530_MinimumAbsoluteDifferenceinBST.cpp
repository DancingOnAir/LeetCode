//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
//    {
//
//    }
//};
//
//void inorderTraversal(TreeNode* root, TreeNode* pre, int& minVal)
//{
//
//    if (root->left)
//        inorderTraversal(root->left, pre, minVal);
//
//    if (pre)
//        minVal = min(minVal, abs(root->val - pre->val));
//    pre = root;
//
//    if (root->right)
//        inorderTraversal(root->right, pre, minVal);
//}
//
//int getMinimumDifference2(TreeNode* root)
//{
//    int minVal = INT_MAX;
//    TreeNode* pre = nullptr;
//    inorderTraversal(root, pre, minVal);
//
//    return minVal;
//}
//
//void helper(TreeNode* root, int& minVal)
//{
//    if (!root)
//        return;
//
//    if (root->left)
//    {
//        TreeNode* tmp = root->left;
//        while (tmp->right)
//            tmp = tmp->right;
//
//        minVal = min(minVal, root->val - tmp->val);
//        helper(root->left, minVal);
//    }
//
//    if (root->right)
//    {
//        TreeNode* tmp = root->right;
//        while (tmp->left)
//            tmp = tmp->left;
//
//        minVal = min(minVal, tmp->val - root->val);
//        helper(root->right, minVal);
//    }
//}
//
//int getMinimumDifference(TreeNode* root)
//{
//    int minVal = INT_MAX;
//    helper(root, minVal);
//
//    return minVal;
//}
//
//TreeNode* createBinaryTree(const vector<string>& nums)
//{
//    if (nums.empty())
//        return nullptr;
//
//    TreeNode* root = new TreeNode(stoi(nums[0]));
//    queue<TreeNode*> q;
//    q.emplace(root);
//    TreeNode* pCurrent = nullptr;
//
//    int startIndex = 1;
//    int nextLevelIndex = 2;
//    int restIndex = nums.size() - 1;
//
//    while (restIndex > 0)
//    {
//        for (int i = startIndex; i < startIndex + nextLevelIndex; i += 2)
//        {
//            if (i >= nums.size())
//                return root;
//
//            pCurrent = q.front();
//            q.pop();
//
//            if (nums[i] != "null")
//            {
//                pCurrent->left = new TreeNode(stoi(nums[i]));
//                q.emplace(pCurrent->left);
//            }
//
//            if (i + 1 >= nums.size())
//                return root;
//
//            if (nums[i + 1] != "null")
//            {
//                pCurrent->right = new TreeNode(stoi(nums[i + 1]));
//                q.emplace(pCurrent->right);
//            }
//        }
//
//        startIndex += nextLevelIndex;
//        restIndex -= nextLevelIndex;
//        nextLevelIndex = q.size() * 2;
//    }
//
//    return root;
//}
//
//void testGetMinimumDifference()
//{
//    vector<string> nums1 = { "1", "null", "3", "2" };
//    TreeNode* root1 = createBinaryTree(nums1);
//    cout << getMinimumDifference(root1) << endl;
//}
//
//int main()
//{
//    testGetMinimumDifference();
//
//    getchar();
//    return 0;
//}