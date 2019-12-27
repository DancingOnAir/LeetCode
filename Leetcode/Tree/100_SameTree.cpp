//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) 
//    {
//
//    }
//};
//
//bool isSameTree(TreeNode* p, TreeNode* q)
//{
//    if (!p && !q)
//        return true;
//
//    if (!p || !q)
//        return false;
//
//    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//TreeNode* createBinaryTree(const vector<string>& bt)
//{
//    if (bt.empty())
//        return nullptr;
//
//    TreeNode* root = new TreeNode(stoi(bt[0]));
//    queue<TreeNode*> q;
//    q.emplace(root);
//
//    TreeNode* pCurrent = nullptr;
//    int startIndex = 1;
//    int restIndex = bt.size() - 1;
//    int nextLevelIndex = 2;
//
//    while (restIndex > 0)
//    {
//        for (int i = startIndex; i < startIndex + nextLevelIndex; i += 2)
//        {
//            if (i == bt.size())
//                return root;
//
//            pCurrent = q.front();
//            q.pop();
//
//            if (bt[i] != "null")
//            {
//                pCurrent->left = new TreeNode(stoi(bt[i]));
//                q.emplace(pCurrent->left);
//            }
//
//            if (i + 1 == bt.size())
//                return root;
//
//            if (bt[i + 1] != "null")
//            {
//                pCurrent->right = new TreeNode(stoi(bt[i + 1]));
//                q.emplace(pCurrent->right);
//            }
//
//            startIndex += nextLevelIndex;
//            restIndex -= nextLevelIndex;
//            nextLevelIndex = q.size() * 2;
//        }
//    }
//
//    return root;
//}
//
//void testIsSameTree()
//{
//    vector<string> vp1 = { "1", "2", "3" };
//    vector<string> vq1 = { "1", "2", "3" };
//    auto p1 = createBinaryTree(vp1);
//    auto q1 = createBinaryTree(vq1);
//    cout << (isSameTree(p1, q1) ? "True" : "False") << endl;
//
//    vector<string> vp2 = { "1", "2" };
//    vector<string> vq2 = { "1", "null", "2" };
//    auto p2 = createBinaryTree(vp2);
//    auto q2 = createBinaryTree(vq2);
//    cout << (isSameTree(p2, q2) ? "True" : "False") << endl;
//
//    vector<string> vp3 = { "1", "2", "1" };
//    vector<string> vq3 = { "1", "1", "2" };
//    auto p3 = createBinaryTree(vp3);
//    auto q3 = createBinaryTree(vq3);
//    cout << (isSameTree(p3, q3) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testIsSameTree();
//
//    getchar();
//    return 0;
//}
