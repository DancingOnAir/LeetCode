//#include <iostream>
//#include <vector>
//#include <stack>
//
//struct TreeNode
//{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) 
//{
//    if (0 == inorder.size() || inorder.size() != postorder.size())
//        return nullptr;
//
//    std::vector<int> in_left, post_left, in_right, post_right;
//    TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
//    int pos = 0;
//
//    for (int i = 0; i < inorder.size(); ++i)
//    {
//        if (inorder[i] == root->val)
//            break;
//
//        ++pos;
//    }
//
//    for (int i = 0; i < pos; ++i)
//    {
//        in_left.push_back(inorder[i]);
//        post_left.push_back(postorder[i]);
//    }
//
//    for (int i = pos + 1; i < inorder.size(); ++i)
//    {
//        in_right.push_back(inorder[i]);
//    }
//
//    for (int i = pos; i < postorder.size() - 1; ++i)
//    {
//        post_right.push_back(postorder[i]);
//    }
//
//    root->left = buildTree(in_left, post_left);
//    root->right = buildTree(in_right, post_right);
//
//    return root;
//}
//
//std::vector<int> postOrderTraverse(TreeNode *root)
//{
//    std::vector<int> result;
//    if (nullptr == root)
//        return result;
//
//    std::stack<TreeNode *> s, t;
//    TreeNode *p = root;
//    s.push(p);
//
//    while (!s.empty())
//    {
//        p = s.top();
//        s.pop();
//        t.push(p);
//        if (p->left)
//            s.push(p->left);
//
//        if (p->right)
//            s.push(p->right);
//    }
//
//    while (!t.empty())
//    {
//        result.push_back(t.top()->val);
//        t.pop();
//    }
//
//    return result;
//}
//
//
//void display(std::vector<int> input)
//{
//    for (int val : input)
//        std::cout << val << ", ";
//    std::cout << std::endl;
//}
//
//int main()
//{
//    std::vector<int> inorder = { 9, 3, 15, 20, 7 };
//    std::vector<int> postorder = { 9, 15, 7, 20, 3 };
//    TreeNode *root = buildTree(inorder, postorder);
//
//    //std::vector<int> result1 = preOrderTraverse(root);
//    //display(result1);
//
//    //std::vector<int> result2 = inOrderTraverse(root);
//    //display(result2);
//
//    std::vector<int> result3 = postOrderTraverse(root);
//    display(result3);
//
//    system("pause");
//    return 0;
//}