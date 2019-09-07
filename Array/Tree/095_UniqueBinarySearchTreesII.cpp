#include <iostream>
#include <vector>
#include <string>

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

//vector<TreeNode *> generateTrees(int start, int end)
//{
//	if (start > end)
//		return vector<TreeNode *>{nullptr};
//
//
//	vector<TreeNode *> result;
//	if (start == end)
//	{
//		TreeNode *p = new TreeNode(start);
//		result.push_back(p);
//		return result;
//	}
//	
//	for (int i = start; i <= end; ++i)
//	{
//		vector<TreeNode *> left = generateTrees(start, i - 1);
//		vector<TreeNode *> right = generateTrees(i + 1, end);
//
//		for (auto lnode : left)
//		{
//			for (auto rnode : right)
//			{
//				TreeNode *root = new TreeNode(i);
//				root->left = lnode;
//				root->right = rnode;
//				result.push_back(root);
//			}
//		}
//	}
//
//	return result;
//}
//
//vector<TreeNode*> generateTrees(int n) 
//{
//	if (n < 1)
//		return vector<TreeNode *>();
//
//	return generateTrees(1, n);
//}
//
//void showTree(TreeNode *root)
//{
//	if (nullptr == root)
//	{
//		cout << "null" << " ";
//		return;
//	}
//	cout << root->val << " ";
//
//	showTree(root->left);
//	showTree(root->right);
//}

vector<TreeNode*> generateTrees(int start, int end)
{
    if (start > end)
        return vector<TreeNode*>{nullptr};

    vector<TreeNode*> res;
    if (start == end)
    {
        TreeNode* p = new TreeNode(start);
        res.emplace_back(p);
        return res;
    }

    for (int i = start; i <= end; ++i)
    {
        vector<TreeNode*> left = generateTrees(start, i - 1);
        vector<TreeNode*> right = generateTrees(i + 1, end);

        for (auto lnode : left)
        {
            for (auto rnode : right)
            {
                TreeNode* root = new TreeNode(i);
                root->left = lnode;
                root->right = rnode;

                res.emplace_back(root);
            }
        }
    }

    return res;
}

vector<TreeNode*> generateTrees(int n)
{
    if (n < 1)
        return vector<TreeNode*>();

    return generateTrees(1, n);
}

void preorderTraversal(TreeNode* root)
{
    if (!root)
        return;

    cout << root->val << ", ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void testGenerateTrees()
{
    int numOfNodes = 3;
    vector<TreeNode*> res = generateTrees(numOfNodes);

    for (auto r : res)
    {
        preorderTraversal(r);
        cout << endl;
    }
}

int main()
{
    testGenerateTrees();

    getchar();
    return 0;
}