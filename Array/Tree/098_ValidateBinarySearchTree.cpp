#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//preorder 
bool isValidBST(TreeNode* root) 
{
	if (nullptr == root)
		return true;

	stack<TreeNode *> stk;
	TreeNode *pCurrent = root;
	vector<int> result;

	while (pCurrent != nullptr || !stk.empty())
	{
		if (pCurrent)
		{
			stk.push(pCurrent);
			pCurrent = pCurrent->left;
		}
		else
		{
			pCurrent = stk.top();
			result.push_back(pCurrent->val);

			pCurrent = pCurrent->right;
			stk.pop();
		}
	}

	for (decltype(result.size()) i = 1; i != result.size(); ++i)
	{
		if (result[i] <= result[i - 1])
			return false;
	}
	return true;
}

int main(void)
{
	TreeNode *root = new TreeNode(1);
	TreeNode *lnode = new TreeNode(2);
	TreeNode *rnode = new TreeNode(3);

	lnode->left = root;
	lnode->right = rnode;


	cout << (isValidBST(root) == true ? "true" : "false") << endl;

	system("pause");
	return 0;
}