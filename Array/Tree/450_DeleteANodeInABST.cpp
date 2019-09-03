//#include <iostream>
//#include <vector>
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
//TreeNode* deleteNode(TreeNode* root, int key)
//{
//    if (nullptr == root)
//        return nullptr;
//
//    if (key == root->val)
//    {
//        if (nullptr == root->right)
//        {
//            TreeNode* left = root->left;
//            delete root;
//            return left;
//        }
//        else
//        {
//            TreeNode* right = root->right;
//            while (right->left)
//                right = right->left;
//
//            swap(root->val, right->val);
//        }
//    }
//    root->left = deleteNode(root->left, key);
//    root->right = deleteNode(root->right, key);
//
//    return root;
//}
//
//void testDeleteNode()
//{
//    TreeNode* node1 = new TreeNode(5);
//    TreeNode* node2 = new TreeNode(3);
//    TreeNode* node3 = new TreeNode(6);
//    TreeNode* node4 = new TreeNode(2);
//    TreeNode* node5 = new TreeNode(4);
//    TreeNode* node6 = new TreeNode(7);
//
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node3->right = node6;
//
//    TreeNode* p = deleteNode(node1, 0);
//    cout << p->val << endl;
//}
//
//int main()
//{
//    testDeleteNode();
//    system("pause");
//    return 0;
//}