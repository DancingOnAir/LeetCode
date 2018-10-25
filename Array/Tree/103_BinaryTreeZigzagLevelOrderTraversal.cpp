#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> result;
    if (nullptr == root)
        return result;

    queue<TreeNode*> q;
    q.emplace(root);
    TreeNode* cur = nullptr;
    vector<int> vals;

    while (!q.empty())
    {
        size_t  len = q.size();
        for (size_t i = 0; i < len; ++i)
        {
            cur = q.front();
            q.pop();

            vals.emplace_back(cur->val);
            if (cur->left)
                q.emplace(cur->left);
            if (cur->right)
                q.emplace(cur->right);
        }


        result.emplace_back(vals);
        vals.clear();
    }

    std::reverse(result.begin(), result.end());

    return result;
}

void display(vector<vector<int>>& input)
{
    if (input.empty())
        return;

    for (auto row : input)
    {
        for (auto col : row)
            cout << col << ", ";
        cout << endl;
    }
}

void testLevelOrderBottom()
{
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(9);
    TreeNode* node3 = new TreeNode(20);
    TreeNode* node4 = new TreeNode(15);
    TreeNode* node5 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    auto result = levelOrderBottom(node1);
    display(result);
}

int main()
{
    testLevelOrderBottom();
    system("pause");
    return 0;
}