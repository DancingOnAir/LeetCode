#include <iostream>
#include <vector>
#include <stack>
#include <string>
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

//void inorder(TreeNode *root, vector<int> &nodes)
//{
//	if (!root)
//		return;
//
//	inorder(root->left, nodes);
//	nodes.push_back(root->val);
//	inorder(root->right, nodes);
//}
//
//vector<int> inorderTraversal(TreeNode* root) 
//{
//	vector<int> results;
//	inorder(root, results);
//
//	return results;
//}
//
//vector<int> inorderTraversal(TreeNode *root)
//{
//	vector<int> results;
//	if (!root)
//		return results;
//
//	stack<TreeNode *> reserve;
//	reserve.push(root);
//
//	while (!reserve.empty())
//	{
//		TreeNode *p = reserve.top();
//		if (root->left)
//		{
//			reserve.push(p->left);
//			p->left = NULL;
//		}
//		else
//		{
//			results.push_back(p->val);
//			reserve.pop();
//
//			if (p->right)
//				reserve.push(p->right);
//		}
//	}
//
//	vector<int> results;
//	stack<TreeNode *> s;
//	TreeNode *pCurrent = root;
//
//	while (!s.empty() || pCurrent)
//	{
//		if (pCurrent)
//		{
//			s.push(pCurrent);
//			pCurrent = pCurrent->left;
//		}
//		else
//		{
//			TreeNode *pNode = s.top();
//			results.push_back(pNode->val);
//			s.pop();
//			pCurrent = pNode->right;
//		}
//	}
//
//	return results;
//}

void inorder(TreeNode* root, vector<int>& nums)
{
    if (!root)
        return;

    inorder(root->left, nums);
    nums.emplace_back(root->val);
    inorder(root->right, nums);
}

vector<int> inorderTraversal2(TreeNode* root)
{
    if (!root)
        return vector<int>();

    vector<int> res;
    inorder(root, res);
    return res;
}

vector<int> inorderTraversal(TreeNode* root)
{
    if (!root)
        return vector<int>();

    vector<int> res;
    stack<TreeNode* > s;
    TreeNode* pCurrentNode = root;
    
    while (!s.empty() || pCurrentNode)
    {
        if (pCurrentNode)
        {
            s.emplace(pCurrentNode);
            pCurrentNode = pCurrentNode->left;
        }
        else
        {
            TreeNode* pTempNode = s.top();
            s.pop();
            res.emplace_back(pTempNode->val);
            pCurrentNode = pTempNode->right;
        }
    }

    return res;
}

TreeNode* createBinaryTree(vector<string>& bt, int pos)
{
    if (bt.empty() || bt[pos] == "null")
    {
        ++pos;
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(bt[pos]));
    return root;
}

void testInorderTraversal()
{
    //vector<string> bt{ "1", "null", "2", "3" };
    //TreeNode* root = createBinaryTree(bt, 0);
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    root->right = node1;
    node1->left = node2;

    vector<int> res = inorderTraversal(root);
    for (int x : res)
        cout << x << ", ";
    cout << endl;
}

int main()
{
    testInorderTraversal();

    getchar();
    return 0;
}
