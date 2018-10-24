//#include <iostream>
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
//int maxToRoot(TreeNode* root, int& max)
//{
//    if (nullptr == root)
//        return 0;
//
//    int l = maxToRoot(root->left, max);
//    int r = maxToRoot(root->right, max);
//
//    if (l < 0)
//        l = 0;
//    if (r < 0)
//        r = 0;
//
//    if (l + r + root->val > max)
//        max = l + r + root->val;
//
//    return root->val += std::max(l, r);
//}
//
//int maxPathSum(TreeNode* root)
//{
//    int max = INT_MIN;
//    maxToRoot(root, max);
//    return max;
//}
//
//void testMaxPathSum()
//{
//    TreeNode* node1 = new TreeNode(-10);
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
//    cout << maxPathSum(node1) << endl;
//}
//
//int main()
//{
//    testMaxPathSum();
//    system("pause");
//    return 0;
//}