//#include <iostream>
//#include <stack>
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
//int kthSmallest2(TreeNode* root, int k)
//{
//    if (root)
//    {
//        auto x = kthSmallest2(root->left, k);
//        return !k ? x : !--k ? root->val : kthSmallest2(root->right, k);
//    }
//}
//
//int kthSmallest(TreeNode* root, int k)
//{
//    stack<TreeNode *> st;
//    TreeNode* cur = root;
//
//    while (!st.empty() || cur != nullptr)
//    {
//        if (cur)
//        {
//            st.emplace(cur);
//            cur = cur->left;
//        }
//        else
//        {
//            TreeNode* temp = st.top();
//            --k;
//            if (0 == k)
//                return temp->val;
//            st.pop();
//            cur = temp->right;
//        }
//    }
//
//    return -1;
//}
//
//void testKthSmallest()
//{
//    TreeNode* node1 = new TreeNode(5);
//    TreeNode* node2 = new TreeNode(3);
//    TreeNode* node3 = new TreeNode(6);
//    TreeNode* node4 = new TreeNode(2);
//    TreeNode* node5 = new TreeNode(4);
//    TreeNode* node6 = new TreeNode(1);
//
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node4->left = node6;
//
//    cout << kthSmallest(node1, 3) << endl;
//}
//
//int main()
//{
//    testKthSmallest();
//    system("pause");
//    return 0;
//}