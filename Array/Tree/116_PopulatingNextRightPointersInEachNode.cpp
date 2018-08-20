#include <iostream>

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

void connect(TreeLinkNode *root) 
{
    if (nullptr == root)
        return;

    if (root->left)
    {
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);
}

int main()
{
    TreeLinkNode *root = new TreeLinkNode(1);
    TreeLinkNode *node2 = new TreeLinkNode(2);
    TreeLinkNode *node3 = new TreeLinkNode(3);
    TreeLinkNode *node4 = new TreeLinkNode(4);
    TreeLinkNode *node5 = new TreeLinkNode(5);
    TreeLinkNode *node6 = new TreeLinkNode(6);
    TreeLinkNode *node7 = new TreeLinkNode(7);

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    connect(root);

    system("pause");
    return 0;
}