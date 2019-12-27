//#include <iostream>
//#include <vector>
//#include <string>
//
//struct TreeLinkNode
//{
//    int val;
//    TreeLinkNode *left, *right, *next;
//    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
//};
//
//TreeLinkNode* findNext(TreeLinkNode* root)
//{
//    if (nullptr == root)
//        return nullptr;
//
//    if (root->left)
//        return root->left;
//
//    if (root->right)
//        return root->right;
//
//    return findNext(root->next);
//}
//
//void connect(TreeLinkNode *root)
//{
//    if (nullptr == root)
//        return;
//
//    if (root->left)
//        root->left->next = (root->right != nullptr) ? root->right : findNext(root->next);
//
//    if (root->right)
//        root->right->next = findNext(root->next);
//
//    connect(root->right);
//    connect(root->left);
//
//}
//
//TreeLinkNode* createBinaryTree(std::vector<std::string> &input)
//{
//
//
//    for (std::string val : input)
//    {
//        TreeLinkNode *node;
//        if ("#" == val)
//            node = nullptr;
//        else
//        {
//            node->val = atoi(val.c_str());
//        }
//    }
//}
//
//int main()
//{
//    TreeLinkNode *root = new TreeLinkNode(1);
//    TreeLinkNode *node2 = new TreeLinkNode(2);
//    TreeLinkNode *node3 = new TreeLinkNode(3);
//    TreeLinkNode *node4 = new TreeLinkNode(4);
//    TreeLinkNode *node5 = new TreeLinkNode(5);
//    TreeLinkNode *node6 = new TreeLinkNode(6);
//    TreeLinkNode *node7 = new TreeLinkNode(7);
//
//    root->left = node2;
//    root->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    //node3->left = node6;
//    node3->right = node7;
//
//    connect(root);
//
//    system("pause");
//    return 0;
//}