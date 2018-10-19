//#include <iostream>
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//bool helper(TreeNode* p, TreeNode* q)
//{
//    if (nullptr == p || nullptr == q)
//        return p == q;
//
//    return (p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left));
//}
//
//bool isSymmetric(TreeNode* root)
//{
//    if (nullptr == root || (nullptr == root->left && nullptr == root->right))
//        return true;
//
//    return helper(root->left, root->right);
//}
//
//void testIsSymmetric()
//{
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(2);
//    TreeNode* node4 = new TreeNode(3);
//    TreeNode* node5 = new TreeNode(4);
//    TreeNode* node6 = new TreeNode(2);
//    TreeNode* node7 = new TreeNode(3);
//
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node3->left = node6;
//    node3->right = node7;
//
//    auto result = isSymmetric(node1);
//    std::cout << result << std::endl;
//}
//
//int main()
//{
//    testIsSymmetric();
//    system("pause");
//    return 0;
//}