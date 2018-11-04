//#include <iostream>
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//};
//
////void postorderTraversal(TreeNode* root, int& count)
////{
////    if (nullptr == root)
////        return;
////
////    ++count;
////    postorderTraversal(root->left, count);
////    postorderTraversal(root->right, count);
////}
//
//int countNodes(TreeNode* root)
//{
//    if (nullptr == root)
//        return 0;
//
//    int leftDepth = 0, rightDepth = 0;
//    for (TreeNode* p = root; p != nullptr; p = p->left)
//        ++leftDepth;
//    for (TreeNode* p = root; p != nullptr; p = p->right)
//        ++rightDepth;
//
//    if (leftDepth == rightDepth)
//        return (1 << leftDepth) - 1;
//    else
//        return 1 + countNodes(root->left) + countNodes(root->right);
//}
//
//void testCountNodes()
//{
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(3);
//    TreeNode* node4 = new TreeNode(4);
//    TreeNode* node5 = new TreeNode(5);
//    TreeNode* node6 = new TreeNode(6);
//
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node3->left = node6;
//
//    std::cout << countNodes(node1) << std::endl;
//}
//
//int main()
//{
//    testCountNodes();
//    system("pause");
//    return 0;
//}