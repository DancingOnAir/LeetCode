//#include <iostream>
//#include <vector>
//#include <stack>
//#include <string>
//#include <deque>
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
//    {
//    }
//};
//
//void inorder(TreeNode* root, vector<int>& nums)
//{
//    if (!root)
//        return;
//
//    inorder(root->left, nums);
//    nums.emplace_back(root->val);
//    inorder(root->right, nums);
//}
//
//vector<int> inorderTraversal2(TreeNode* root)
//{
//    if (!root)
//        return vector<int>();
//
//    vector<int> res;
//    inorder(root, res);
//    return res;
//}
//
//vector<int> inorderTraversal(TreeNode* root)
//{
//    if (!root)
//        return vector<int>();
//
//    vector<int> res;
//    stack<TreeNode* > s;
//    TreeNode* pCurrentNode = root;
//    
//    while (!s.empty() || pCurrentNode)
//    {
//        if (pCurrentNode)
//        {
//            s.emplace(pCurrentNode);
//            pCurrentNode = pCurrentNode->left;
//        }
//        else
//        {
//            TreeNode* pTempNode = s.top();
//            s.pop();
//            res.emplace_back(pTempNode->val);
//            pCurrentNode = pTempNode->right;
//        }
//    }
//
//    return res;
//}
//
//TreeNode* createBinaryTree(const vector<string>& nums)
//{
//    if (nums.empty())
//    {
//        return nullptr;
//    }
//
//    TreeNode* root = new TreeNode(stoi(nums[0]));
//    int nextLevel = 2;
//    int pos = 1;
//    int restNum = nums.size() - 1;
//    deque<TreeNode*> q;
//    TreeNode* pCurrent = nullptr;
//    q.emplace_back(root);
//
//    while (restNum > 0)
//    {
//        for (int i = pos; i < pos + nextLevel; i += 2)
//        {
//            if (i == nums.size())
//                return root;
//
//            pCurrent = q.front();
//            q.pop_front();
//            if (nums[i] != "null")
//            {
//                pCurrent->left = new TreeNode(stoi(nums[i]));
//                q.emplace_back(pCurrent->left);
//            }
//
//            if (i + 1 == nums.size())
//                return root;
//
//            if (nums[i + 1] != "null")
//            {
//                pCurrent->right = new TreeNode(stoi(nums[i + 1]));
//                q.emplace_back(pCurrent->right);
//            }
//        }
//        pos += nextLevel;
//        restNum -= nextLevel;
//        nextLevel = q.size() * 2;
//    }
//
//    return root;
//}
//
//void testInorderTraversal()
//{
//    vector<string> bt{ "1", "null", "2", "3" };
//    TreeNode* root = createBinaryTree(bt);
//
//    vector<int> res = inorderTraversal(root);
//    for (int x : res)
//        cout << x << ", ";
//    cout << endl;
//}
//
//int main()
//{
//    testInorderTraversal();
//
//    getchar();
//    return 0;
//}
