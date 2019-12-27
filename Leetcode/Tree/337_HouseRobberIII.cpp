//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//};
//
////int getMaxSub(vector<int>& nums)
////{
////    if (0 == nums.size())
////        return 0;
////
////    if (1 == nums.size())
////        return nums[0];
////
////    if (2 == nums.size())
////        return max(nums[0], nums[1]);
////
////    if (3 == nums.size())
////        return max(nums[0] + nums[2], nums[1]);
////
////    vector<int> maxSub(nums.size());
////    maxSub[0] = nums[0];
////    maxSub[1] = max(nums[0], nums[1]);
////    maxSub[2] = max(nums[0] + nums[2], nums[1]);
////    int result = max(max(maxSub[0], maxSub[1]), maxSub[2]);
////    for (auto i = 3; i < nums.size(); ++i)
////    {
////        maxSub[i] = max(maxSub[i - 2], maxSub[i - 3]) + nums[i];
////        result = max(result, maxSub[i]);
////    }
////
////    return result;
////}
//
//int robRecursive(TreeNode* root, int& l, int& r)
//{
//    if (nullptr == root)
//        return 0;
//
//    int ll = 0, lr = 0, rl = 0, rr = 0;
//    l = robRecursive(root->left, ll, lr);
//    r = robRecursive(root->right, rl, rr);
//
//    return max(root->val + ll + lr + rl + rr, r + l);
//}
//
//int rob(TreeNode* root)
//{
//    int l = 0, r = 0;
//
//    return robRecursive(root, l, r);
//}
//
//void testRob()
//{
//    TreeNode* node1 = new TreeNode(4);
//    TreeNode* node2 = new TreeNode(1);
//    TreeNode* node3 = new TreeNode(2);
//    TreeNode* node4 = new TreeNode(3);
//    node1->left = node2;
//    node2->left = node3;
//    node3->left = node4;
//
//    cout << rob(node1) << endl;
//}
//
//int main()
//{
//    testRob();
//    system("pause");
//    return 0;
//}