//#include <iostream>
//#include <vector>
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
//void helper(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int sum, int cur)
//{
//    if (nullptr == root)
//        return;
//
//    cur += root->val;
//    path.emplace_back(root->val);
//    if (nullptr == root->left && nullptr == root->right)
//    {
//        if (cur == sum)
//            result.emplace_back(path);
//
//        path.pop_back();
//        cur -= root->val;
//
//        return;
//    }
//
//    helper(root->left, result, path, sum, cur);
//    helper(root->right, result, path, sum, cur);
//    path.pop_back();
//    cur -= root->val;
//}
//
//vector<vector<int>> pathSum(TreeNode* root, int sum)
//{
//    vector<vector<int>> result;
//    if (nullptr == root)
//        return result;
//
//    vector<int> path;
//    helper(root, result, path, sum, 0);
//
//    return result;
//}
//
//void display(vector<vector<int>>& result)
//{
//    if (result.empty())
//        return;
//
//    for (auto row : result)
//    {
//        for (auto col : row)
//            cout << col << ", ";
//
//        cout << endl;
//    }
//
//    return;
//}
//
//void testPathSum()
//{
//    TreeNode* node1 = new TreeNode(5);
//    TreeNode* node2 = new TreeNode(4);
//    TreeNode* node3 = new TreeNode(8);
//    TreeNode* node4 = new TreeNode(11);
//    TreeNode* node5 = new TreeNode(13);
//    TreeNode* node6 = new TreeNode(4);
//    TreeNode* node7 = new TreeNode(7);
//    TreeNode* node8 = new TreeNode(2);
//    TreeNode* node9 = new TreeNode(5);
//    TreeNode* node10 = new TreeNode(1);
//
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node3->left = node5;
//    node3->right = node6;
//    node4->left = node7;
//    node4->right = node8;
//    node6->left = node9;
//    node6->right = node10;
//
//    auto result = pathSum(node1, 22);
//    display(result);
//}
//
//int main()
//{
//    testPathSum();
//    system("pause");
//    return 0;
//}