//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//class BSTIterator {
//public:
//    BSTIterator(TreeNode *root)
//    {
//        pushTreeNode(root);
//    }
//
//    /** @return whether we have a next smallest number */
//    bool hasNext()
//    {
//        return !st.empty();
//    }
//
//    /** @return the next smallest number */
//    int next()
//    {
//        TreeNode* temp = st.top();
//        st.pop();
//        pushTreeNode(temp->right);
//        return temp->val;
//        
//    }
//
//    void pushTreeNode(TreeNode* root)
//    {
//        for (; root != nullptr; root = root->left)
//            st.emplace(root);
//    }
//
//private:
//    stack<TreeNode*> st;
//};
//
//void testBSTIterator()
//{
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(3);
//    TreeNode* node4 = new TreeNode(4);
//    TreeNode* node5 = new TreeNode(5);
//    TreeNode* node6 = new TreeNode(6);
//    TreeNode* node7 = new TreeNode(7);
//    TreeNode* node8 = new TreeNode(8);
//    TreeNode* node9 = new TreeNode(9);
//    
//    node5->left = node2;
//    node5->right = node7;
//    node2->left = node1;
//    node2->right = node3;
//    node7->left = node6;
//    node7->right = node9;
//    node3->right = node4;
//    node9->left = node8;
//
//    BSTIterator bstIterator(node5);
//    bool result = bstIterator.hasNext();
//    cout << (result ? "true" : "false") << endl;
//    cout << bstIterator.next() << endl;
//}
//
//int main()
//{
//
//    system("pause");
//    return 0;
//}