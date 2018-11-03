//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//};
//
//
//TreeNode* first = nullptr;
//TreeNode* second = nullptr;
//TreeNode* pre = new TreeNode(INT_MIN);
//
//void inorderTraversal(TreeNode* root)
//{
//    if (nullptr == root)
//        return;
//
//    inorderTraversal(root->left);
//    
//    if (first == nullptr && pre->val >= root->val)
//        first = pre;
//
//    if (first != nullptr && pre->val >= root->val)
//        second = root;
//
//    pre = root;
//    inorderTraversal(root->right);
//}
//
//void recoverTree(TreeNode* root) 
//{
//    inorderTraversal(root);
//    swap(first->val, second->val);
//}
//
//void testRecoverTree()
//{
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(3);
//    TreeNode* node4 = new TreeNode(4);
//
//    node3->left = node1;
//    node3->right = node4;
//    node4->left = node2;
//
//    recoverTree(node3);
//    cout << node3->val << endl;
//}
//
//int main()
//{
//    testRecoverTree();
//    system("pause");
//    return 0;
//}