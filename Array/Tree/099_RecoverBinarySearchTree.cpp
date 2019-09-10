#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {

    }
};

TreeNode* first = nullptr;
TreeNode* second = nullptr;
TreeNode* pre = new TreeNode(INT_MIN);

void inorderTraversal(TreeNode* root)
{
    if (!root)
        return;

    inorderTraversal(root->left);
    
    if (!first && pre->val >= root->val && root->val != INT_MIN)
        first = pre;

    if (first && pre->val >= root->val)
        second = root;

    pre = root;

    inorderTraversal(root->right);
}

void recoverTree(TreeNode* root)
{
    if (!root)
        return;

    inorderTraversal(root);
    swap(first->val, second->val);
}

TreeNode* createBinaryTree(vector<string>& bt)
{
    if (bt.empty())
        return nullptr;

    TreeNode* root = new TreeNode(stoi(bt[0]));
    queue<TreeNode*> q;
    q.emplace(root);

    TreeNode* pCurrent = nullptr;

    int startIndex = 1;
    int nextLevel = 2;
    int restIndex = bt.size() - 1;

    while (restIndex > 0)
    {
        for (int i = startIndex; i < startIndex + nextLevel; i += 2)
        {
            if (i == bt.size())
                return root;

            pCurrent = q.front();
            q.pop();
            if (bt[i] != "null")
            {
                pCurrent->left = new TreeNode(stoi(bt[i]));
                q.emplace(pCurrent->left);
            }

            if (i + 1 == bt.size())
                return root;

            if (bt[i + 1] != "null")
            {
                pCurrent->right = new TreeNode(stoi(bt[i + 1]));
                q.emplace(pCurrent->right);
            }

            startIndex += nextLevel;
            restIndex -= nextLevel;
            nextLevel = q.size() * 2;
        }
    }

    return root;
}

void inorderDisplay(TreeNode* root)
{
    if (!root)
        return;

    inorderDisplay(root->left);
    cout << root->val << endl;
    inorderDisplay(root->right);
}

void testRecoverTree()
{
    vector<string> bt1 = { "5","3","9","-2147483648","2" };
    auto root1 = createBinaryTree(bt1);
    recoverTree(root1);
    inorderDisplay(root1);

    vector<string> bt2 = { "3", "1", "4", "null", "null", "2" };
    auto root2 = createBinaryTree(bt2);
    recoverTree(root2);
    inorderDisplay(root2);
}

int main()
{
    testRecoverTree();

    getchar();
    return 0;
}

//using namespace std;
//
//
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//};
//
//
//TreeNode* first = nullptr;
//TreeNode* second = nullptr;
//TreeNode* pre = new TreeNode(INT_MIN);
//
//void inorderTraversal(TreeNode* root)
//{
//    if (nullptr == root)
//        return;
//
//    inorderTraversal(root->left);
//    
//    if (first == nullptr && pre->val >= root->val)
//        first = pre;
//
//    if (first != nullptr && pre->val >= root->val)
//        second = root;
//
//    pre = root;
//    inorderTraversal(root->right);
//}
//
//void recoverTree(TreeNode* root) 
//{
//    inorderTraversal(root);
//    swap(first->val, second->val);
//}

//void testRecoverTree()
//{
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(3);
//    TreeNode* node4 = new TreeNode(4);
//
//    node3->left = node1;
//    node3->right = node4;
//    node4->left = node2;
//
//    recoverTree(node3);
//    cout << node3->val << endl;
//}
//
//int main()
//{
//    testRecoverTree();
//    system("pause");
//    return 0;
//}