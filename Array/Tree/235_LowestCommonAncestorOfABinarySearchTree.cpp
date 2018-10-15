#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode *> getPath(TreeNode* root, TreeNode* target)
{
    vector<TreeNode *> path;
    if (nullptr == root || nullptr == target)
        return path;

    while (root != target)
    {
        path.push_back(root);

        if (root->val > target->val)
            root = root->left;
        else
            root = root->right;
    }

    path.push_back(root);
    return path;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (nullptr == root || nullptr == p || nullptr == q)
        return nullptr;

    vector<TreeNode *> p1 = getPath(root, p);
    vector<TreeNode *> p2 = getPath(root, q);

    size_t index = std::min(p1.size(), p2.size());
    for (size_t i = 0; i < index; ++i)
        if (p1[i] != p2[i])
            return p1[i - 1];

    return p1[index - 1];
}

void testLowestCommonAncestor()
{
    TreeNode* node1 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(0);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(9);
    TreeNode* node8 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;

    TreeNode* result = lowestCommonAncestor(node1, node2, node5);
    cout << result->val << endl;
}

int main()
{
    testLowestCommonAncestor();
    system("pause");
    return 0;
}