#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<int> rightSideView(TreeNode* root)
{
    vector<int> result;
    if (nullptr == root)
        return result;

    TreeNode* cur = nullptr;
    queue<TreeNode *> q;
    q.emplace(root);
    size_t len = 0;

    while (!q.empty())
    {
        len = q.size();

        for (auto i = 0; i < len; ++i)
        {
            cur = q.front();
            q.pop();

            if (i == len - 1)
                result.emplace_back(cur->val);

            if (cur->left)
                q.emplace(cur->left);

            if (cur->right)
                q.emplace(cur->right);
        }
    }

    return result;
}

void display(vector<int>& nums)
{
    if (nums.empty())
        return;

    for (auto& x : nums)
        cout << x << endl;
}

void testRightSideView()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(4);
    
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    //node3->right = node5;

    auto result = rightSideView(node1);
    display(result);
}

int main()
{
    testRightSideView();
    system("pause");
    return 0;
}