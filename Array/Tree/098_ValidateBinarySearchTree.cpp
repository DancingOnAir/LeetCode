//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//#include <stack>
//
//using namespace std;
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//};
//
//bool isValidBST(TreeNode* root)
//{
//    if (!root)
//        return true;
//
//    stack<TreeNode*> stk;
//    TreeNode* pCurrent = root;
//    vector<int> nums;
//
//    while (!stk.empty() || pCurrent)
//    {
//        if (pCurrent)
//        {
//            stk.emplace(pCurrent);
//            pCurrent = pCurrent->left;
//        }
//        else
//        {
//            pCurrent = stk.top();
//            stk.pop();
//
//            nums.emplace_back(pCurrent->val);
//            pCurrent = pCurrent->right;
//        }
//    }
//
//    for (int i = 0; i < nums.size() - 1; ++i)
//    {
//        if (nums[i] >= nums[i + 1])
//            return false;
//    }
//
//    return true;
//}
//
//TreeNode* createBinaryTree(vector<string>& bt)
//{
//    if (bt.empty())
//        return nullptr;
//
//    queue<TreeNode*> q;
//    TreeNode* root = new TreeNode(stoi(bt[0]));
//    q.emplace(root);
//    
//    TreeNode* pCurrent = nullptr;
//    int nextLevel = 2;
//    int pos = 1;
//    int rest = bt.size() - 1;
//    while (rest > 0)
//    {
//        for (int i = pos; i < pos + nextLevel; i += 2)
//        {
//            if (i == bt.size())
//                return nullptr;
//
//            pCurrent = q.front();
//            q.pop();
//            if (bt[i] != "null")
//            {
//                pCurrent->left = new TreeNode(stoi(bt[i]));
//                q.emplace(pCurrent->left);
//            }
//
//            if (i + 1 == bt.size())
//                return nullptr;
//
//            if (bt[i + 1] != "null")
//            {
//                pCurrent->right = new TreeNode(stoi(bt[i + 1]));
//                q.emplace(pCurrent->right);
//            }
//        }
//        pos += nextLevel;
//        rest -= nextLevel;
//        nextLevel = q.size() * 2;
//    }
//
//    return root;
//}
//
//void testIsValidBST()
//{
//    vector<string> bt1 = { "2", "1", "3" };
//    TreeNode* root1 = createBinaryTree(bt1);
//    cout << (isValidBST(root1) ? "True" : "False") << endl;
//
//    vector<string> bt2 = { "5", "1", "4", "null", "null", "3", "6" };
//    TreeNode* root2 = createBinaryTree(bt2);
//    cout << (isValidBST(root2) ? "True" : "False") << endl;
//}
//
//int main(void)
//{
//    testIsValidBST();
//
//    getchar();
//    return 0;
//}
