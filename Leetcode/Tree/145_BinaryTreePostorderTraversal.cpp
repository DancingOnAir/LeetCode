//#include <iostream>
//#include <vector>
//#include <stack>
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
//vector<int> postorderTraversal(TreeNode* root)
//{
//    vector<int> result;
//    if (nullptr == root)
//        return result;
//    
//    TreeNode* cur = nullptr;
//    stack<TreeNode *> s, t;
//    s.push(root);
//
//    while (!s.empty())
//    {
//        cur = s.top();
//        t.push(cur);
//        s.pop();
//
//        if (cur->left)
//            s.push(cur->left);
//        if (cur->right)
//            s.push(cur->right);
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
//void display(vector<int>& nums)
//{
//    if (nums.empty())
//        return;
//
//    for (auto i = 0; i < nums.size(); ++i)
//        cout << nums[i] << ", ";
//    cout << endl;
//}
//
//void testPostorderTraversal()
//{
//    TreeNode* node1 = new TreeNode(6);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(8);
//    TreeNode* node4 = new TreeNode(0);
//    TreeNode* node5 = new TreeNode(4);
//    TreeNode* node6 = new TreeNode(7);
//    TreeNode* node7 = new TreeNode(9);
//    TreeNode* node8 = new TreeNode(3);
//    TreeNode* node9 = new TreeNode(5);
//    
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node3->left = node6;
//    node3->right = node7;
//    node5->left = node8;
//    node5->right = node9;
//
//    vector<int> result = postorderTraversal(node1);
//    display(result);
//}
//
//int main()
//{
//    testPostorderTraversal();
//
//    system("pause");
//    return 0;
//}