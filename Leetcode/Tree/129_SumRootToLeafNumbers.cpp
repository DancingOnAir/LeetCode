//#include <iostream>
//#include <vector>
//#include <string>
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
//void helper(TreeNode* root, vector<int>& result, string& path)
//{
//    if (nullptr == root)
//        return;
//
//    //path.emplace_back(root->val);
//    path += to_string(root->val);
//    if (nullptr == root->left && nullptr == root->right)
//    {
//        result.emplace_back(stoi(path));
//        path.pop_back();
//        return;
//    }
//
//    helper(root->left, result, path);
//    helper(root->right, result, path);
//    path.pop_back();
//}
//
//int getSum(vector<int> result)
//{
//    int sum = 0;
//    for (auto x : result)
//        sum += x;
//
//    return sum;
//}
//
//int sumNumbers(TreeNode* root)
//{
//    if (nullptr == root)
//        throw std::exception("invalid parameters");
//
//    vector<int> result;
//    string path;
//    helper(root, result, path);
//    return getSum(result);
//}
//
//void testSumNumbers()
//{
//    TreeNode* node1 = new TreeNode(4);
//    TreeNode* node2 = new TreeNode(9);
//    TreeNode* node3 = new TreeNode(0);
//    TreeNode* node4 = new TreeNode(5);
//    TreeNode* node5 = new TreeNode(1);
//
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//
//    auto result = sumNumbers(node1);
//    cout << result << endl;
//}
//
//int main()
//{
//    testSumNumbers();
//    system("pause");
//    return 0;
//}