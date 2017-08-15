#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode *> generateTrees(int start, int end)
{
	if (start > end)
		return vector<TreeNode *>{nullptr};


	vector<TreeNode *> result;
	if (start == end)
	{
		TreeNode *p = new TreeNode(start);
		result.push_back(p);
		return result;
	}
	
	for (int i = start; i <= end; ++i)
	{
		vector<TreeNode *> left = generateTrees(start, i - 1);
		vector<TreeNode *> right = generateTrees(i + 1, end);

		for (auto lnode : left)
		{
			for (auto rnode : right)
			{
				TreeNode *root = new TreeNode(i);
				root->left = lnode;
				root->right = rnode;
				result.push_back(root);
			}
		}
	}

	return result;
}

vector<TreeNode*> generateTrees(int n) 
{
	if (n < 1)
		return vector<TreeNode *>();

	return generateTrees(1, n);
}

void showTree(TreeNode *root)
{
	if (nullptr == root)
	{
		cout << "null" << " ";
		return;
	}
	cout << root->val << " ";

	showTree(root->left);
	showTree(root->right);
}

int main(void)
{
	int numOfNodes = 3;
	vector<TreeNode *> result = generateTrees(numOfNodes);

	for (auto tree : result)
	{
		showTree(tree);
		cout << endl;
	}

	system("pause");
	return 0;
}