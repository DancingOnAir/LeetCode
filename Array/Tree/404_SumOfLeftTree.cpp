//#include <iostream>
//
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
//void postorderTraversal(TreeNode* root, int& sum)
//{
//    if (nullptr == root)
//        return;
//
//    if (root->left && nullptr == root->left->left && nullptr == root->left->right)
//        sum += root->left->val;
//
//    postorderTraversal(root->left, sum);
//    postorderTraversal(root->right, sum);
//}
//
//int sumOfLeftLeaves(TreeNode* root)
//{
//    if (nullptr == root)
//        return 0;
//
//    int sum = 0;
//    postorderTraversal(root, sum);
//
//    return sum;
//}
//
//void testSumOfLeftLeaves()
//{
//    TreeNode* node1 = new TreeNode(3);
//    TreeNode* node2 = new TreeNode(9);
//    TreeNode* node3 = new TreeNode(20);
//    TreeNode* node4 = new TreeNode(15);
//    TreeNode* node5  = new TreeNode(7);
//
//    node1->left = node2;
//    node1->right = node3;
//    node3->left = node4;
//    node3->right = node5;
//
//    cout << sumOfLeftLeaves(node1) << endl;
//}
//
//int main()
//{
//    testSumOfLeftLeaves();
//    system("pause");
//    return 0;
//}