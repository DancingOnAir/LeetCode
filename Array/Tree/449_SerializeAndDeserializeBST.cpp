#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root)
{
    if (nullptr == root)
        return "null ";

    printf("%d", root->val);
    return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
}

TreeNode* deserializeHelper(istringstream& iss)
{
    TreeNode* root = nullptr;
    string word;
    if (iss >> word && word != "null")
    {
        root = new TreeNode(stoi(word));
        root->left = deserializeHelper(iss);
        root->right = deserializeHelper(iss);
    }

    return root;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string& data)
{
    istringstream iss(data);
    return deserializeHelper(iss);
}

void preorderTraversal(TreeNode* root)
{
    if (nullptr == root)
        return;

    stack<TreeNode *> st;
    st.emplace(root);
    TreeNode* cur = nullptr;

    while (!st.empty())
    {

        cur = st.top();
        cout << cur->val << endl;
        st.pop();

        if (cur->right)
            st.emplace(cur->right);
        if (cur->left)
            st.emplace(cur->left);
    }
}


void testSerialize()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    string str = serialize(node1);
    cout << str << endl;
    auto result = deserialize(str);
    preorderTraversal(result);
}

int main()
{
    testSerialize();
    system("pause");
    return 0;
}