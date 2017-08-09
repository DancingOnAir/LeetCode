#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root, vector<int> &nodes)
{
	if (!root)
		return;

	inorder(root->left, nodes);
	nodes.push_back(root->val);
	inorder(root->right, nodes);
}

vector<int> inorderTraversal(TreeNode* root) 
{
	vector<int> results;
	inorder(root, results);

	return results;
}

int main(void)
{


	system("pause");
	return 0;
}