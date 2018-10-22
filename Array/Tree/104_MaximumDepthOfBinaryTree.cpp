//#include <iostream>
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
//int maxDepth(TreeNode* root)
//{
//    if (nullptr == root)
//        return 0;
//
//    int l = 1 + maxDepth(root->left);
//    int r = 1 + maxDepth(root->right);
//
//    return l > r ? l : r;
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
//    cout << maxDepth(node1) << endl;
//}
//
//int main()
//{
//    testMaxDepth();
//    system("pause");
//    return 0;
//}