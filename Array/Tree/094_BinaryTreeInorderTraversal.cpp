#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> results;
	if (!root)
		return results;

	stack<TreeNode *> reserve;
	reserve.push(root);

	while (!reserve.empty())
	{
		TreeNode *p = reserve.top();
		if (root->left)
		{
			reserve.push(p->left);
			p->left = NULL;
		}
		else
		{
			results.push_back(p->val);
			reserve.pop();

			if (p->right)
				reserve.push(p->right);
		}
	}

	return results;
}

int main(void)
{


	system("pause");
	return 0;
}