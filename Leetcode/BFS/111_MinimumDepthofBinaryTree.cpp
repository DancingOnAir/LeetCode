#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};

int minDepth(TreeNode* root) 
{
    int result = 0;
    if (!root)
        return result;

    vector<vector<int>> v;
    list<TreeNode *> queue;
    queue.push_back(root);

    while (!queue.empty())
    {
        int len = queue.size();
        vector<int> vals;

        for (int i = 0; i < len; ++i)
        {
            TreeNode *temp = queue.front();
            queue.pop_front();
            vals.push_back(temp->val);

            if (temp->left)
                queue.push_back(temp->left);
            if (temp->right)
                queue.push_back(temp->right);

            if (!temp->left && !temp->right)
            {
                result = v.size();
                return result + 1;
            }
        }

        v.push_back(vals);
    }

    return result;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);

    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;

    int result = minDepth(root);

    std::cout << result << std::endl;

    system("pause");
    return 0;
}