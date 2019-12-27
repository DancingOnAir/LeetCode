//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <list>
//
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
//    {
//    }
//};
//
////void recursiveHelper(vector<vector<int>> *dest, vector<TreeNode*> currentLevel)
////{
////    if (!currentLevel.empty())
////    {
////        vector<TreeNode *> nextLevel;
////        vector<int> vals;
////        for (const auto &node : currentLevel)
////        {
////            vals.push_back(node->val);
////            if (node->left)
////                nextLevel.push_back(node->left);
////            if (node->right)
////                nextLevel.push_back(node->right);
////        }
////
////        recursiveHelper(dest, nextLevel);
////        dest->push_back(vals);
////    }
////}
////
////vector<vector<int>> levelOrderBottom(TreeNode *root)
////{
////    vector<vector<int>> result;
////
////    if (root)
////    {
////        vector<TreeNode*> rootLevel = { root };
////        recursiveHelper(&result, rootLevel);
////    }
////
////    return result;
////}
//
//vector<vector<int>> levelOrderBottom(TreeNode *root)
//{
//    vector<vector<int>> result;
//
//    if (!root)
//        result;
//
//    list<TreeNode *> queue;
//    queue.push_back(root);
//
//    while (!queue.empty())
//    {
//        vector<int> vals;
//
//        int len = queue.size();
//        for (int i = 0; i < len; ++i)
//        {
//            TreeNode *temp = queue.front();
//            queue.pop_front();
//            vals.push_back(temp->val);
//
//            if (temp->left != nullptr)
//                queue.push_back(temp->left);
//            if (temp->right != nullptr)
//                queue.push_back(temp->right);
//        }
//
//        result.push_back(vals);
//    }
//
//    vector<vector<int>> reversedResult;
//
//    for (int i = result.size() - 1; i >= 0; i--)
//    {
//        reversedResult.push_back(result.at(i));
//    }
//    return reversedResult;
//}
//
//int main()
//{
//    TreeNode *root = new TreeNode(3);
//    TreeNode *node1 = new TreeNode(9);
//    TreeNode *node2 = new TreeNode(20);
//    TreeNode *node3 = new TreeNode(15);
//    TreeNode *node4 = new TreeNode(7);
//
//    root->left = node1;
//    root->right = node2;
//    node2->left = node3;
//    node2->right = node4;
//
//    vector<vector<int>> result = levelOrderBottom(root);
//
//    for (auto row : result)
//    {
//        for (auto col : row)
//            std::cout << col << ", ";
//
//        std::cout << std::endl;
//    }
//
//    system("pause");
//    return 0;
//}
