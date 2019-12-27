//#include <iostream>
//#include <stack>
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//};
//
//void flatten(TreeNode* root)
//{
//    if (nullptr == root)
//        return;
//
//    TreeNode* cur = root;
//    while (cur)
//    {
//        if (cur->left)
//        {
//            TreeNode* pre = cur->left;
//            while (pre->right)
//                pre = pre->right;
//
//            pre->right = cur->right;
//
//            cur->right = cur->left;
//            cur->left = nullptr;
//        }
//
//        cur = cur->right;
//    }
//}
//
//void flatten1(TreeNode* root)
//{
//    if (nullptr == root)
//        return;
//
//    std::stack<TreeNode*> s;
//    s.emplace(root);
//    TreeNode* cur = nullptr;
//    TreeNode* head = root;
//
//    while (!s.empty())
//    {
//        cur = s.top();
//        s.pop();
//        
//        if (cur->right)
//            s.emplace(cur->right);
//        if (cur->left)
//            s.emplace(cur->left);
//
//        head->left = nullptr;
//        head->right = cur;
//        head = head->right;
//    }
//}
//
//void inorderTraversal(TreeNode* root)
//{
//    if (nullptr == root)
//        return;
//
//    inorderTraversal(root->left);
//    std::cout << root->val << std::endl;
//    inorderTraversal(root->right);
//}
//
//void testFlatten()
//{
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(3);
//    TreeNode* node4 = new TreeNode(4);
//    TreeNode* node5 = new TreeNode(5);
//    TreeNode* node6 = new TreeNode(6);
//
//    node1->left = node2;
//    node1->right = node5;
//    node2->left = node3;
//    node2->right = node4;
//    node5->right = node6;
//
//    inorderTraversal(node1);
//    flatten(node1);
//    inorderTraversal(node1);
//}
//
//int main()
//{
//    testFlatten();
//    system("pause");
//    return 0;
//}