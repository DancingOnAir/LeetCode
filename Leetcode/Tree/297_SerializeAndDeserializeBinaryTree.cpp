//#include <iostream>
//#include <string>
//#include <queue>
//#include <vector>
//#include <sstream>
//
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
//// Encodes a tree to a single string.
//string serialize(TreeNode* root)
//{
//    string result;
//    if (nullptr == root)
//        return result;
//
//    queue<TreeNode*> q;
//    q.emplace(root);
//    TreeNode* cur = nullptr;
//
//    while (!q.empty())
//    {
//        cur = q.front();
//        q.pop();
//
//        if (cur)
//        {
//            result += std::to_string(cur->val) + " ";
//
//            q.emplace(cur->left);
//            q.emplace(cur->right);
//        }
//        else
//            result += "null ";
//    }
//
//    return result;
//}
//
//TreeNode* deserializeHelper(istringstream& iss)
//{
//    TreeNode* root = nullptr;
//    string word;
//    if (iss >> word && word != "null")
//    {
//        root = new TreeNode(stoi(word));
//        root->left = deserializeHelper(iss);
//        root->right = deserializeHelper(iss);
//    }
//
//    return root;
//}
//
//// Decodes your encoded data to tree.
//TreeNode* deserialize(string data)
//{
//    istringstream iss(data);
//    return deserializeHelper(iss);
//}
//
//string serialize2(TreeNode* root)
//{
//    if (root == nullptr) return "null ";
//    return to_string(root->val) + " " + serialize2(root->left) + serialize2(root->right);
//}
//
//void displayBinaryTree(TreeNode* root)
//{
//    if (nullptr == root)
//        return;
//
//    cout << root->val << endl;
//    displayBinaryTree(root->left);
//    displayBinaryTree(root->right);
//}
//
//void testSerialize()
//{
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(3);
//    TreeNode* node4 = new TreeNode(4);
//    TreeNode* node5 = new TreeNode(5);
//
//    node1->left = node2;
//    node1->right = node3;
//    node3->left = node4;
//    node3->right = node5;
//
//    //node1->right = node2;
//    //node2->left = node3;
//
//    string result1 = serialize2(node1);
//    cout << result1 << endl;
//
//    TreeNode* result2 = deserialize(result1);
//    displayBinaryTree(result2);
//}
//
//int main()
//{
//    testSerialize();
//    system("pause");
//    return 0;
//}