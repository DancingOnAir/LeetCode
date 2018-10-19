#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void helper(TreeNode* root, vector<string>& result, string& str)
{
    if (nullptr == root)
        return;

    if (nullptr == root->left && nullptr == root->right)
    {
        result.emplace_back(str);
        return;
    }

    if (root->left)
        helper(root->left, result, str + "->" + to_string(root->left->val));
    if (root->right)
        helper(root->right, result, str + "->" + to_string(root->right->val));


}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> result;
    if (nullptr == root)
        return result;

    string str(to_string(root->val));
    helper(root, result, str);

    return result;
}

void display(vector<string>& str)
{
    for (auto s : str)
        cout << s << ", ";
    cout << endl;
}

void testBinaryTreePaths()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    auto result = binaryTreePaths(node1);
    display(result);
}

int main()
{
    testBinaryTreePaths();
    system("pause");
    return 0;
}