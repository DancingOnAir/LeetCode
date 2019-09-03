#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {

    }
};

vector<int> findMode2(TreeNode* root)
{
    if (root == nullptr)
        return vector<int>();

    vector<int> res;
    unordered_map<int, int> m;
    stack<TreeNode*> s;
    int maxValue = INT_MIN;
    while (root || !s.empty())
    {
        while (root)
        {
            m[root->val]++;
            maxValue = maxValue > m[root->val] ? maxValue : m[root->val];
            s.emplace(root);
            root = root->left;
        }

        if (!s.empty())
        {
            root = s.top();
            root = root->right;
            s.pop();
        }
    }

    for (auto v : m)
    {
        if (v.second == maxValue)
            res.emplace_back(v.first);
    }

    return res;
}

int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
vector<int> res;

void inorderTraversal(TreeNode* root)
{
    if (!root)
        return;

    inorderTraversal(root->left);
    if (precursor == root->val)
        ++currFreq;
    else
        currFreq = 1;

    if (currFreq > maxFreq)
    {
        maxFreq = 1;
        res.clear();
        res.emplace_back(root->val);
    }
    else if (currFreq == maxFreq)
    {
        res.emplace_back(root->val);
    }

    precursor = root->val;
    inorderTraversal(root->right);
}

vector<int> findMode(TreeNode* root)
{
    inorderTraversal(root);
    return res;
}

TreeNode* generateBST(vector<string>& bst, int pos)
{
    if (bst.empty() || pos >= bst.size() || bst[pos] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(bst[pos]));
    root->left = generateBST(bst, pos + 1);
    root->right = generateBST(bst, pos + 2);

    return root;
}

void testFindMode()
{
    vector<string> bst = { "1", "null", "2", "2" };
    auto root = generateBST(bst, 0);
    auto res = findMode(root);
    for (int x : res)
        cout << x << ", ";
    cout << endl;
}

int main()
{
    testFindMode();

    getchar();
    return 0;
}