////#include <iostream>
////using namespace std;
////
////struct TreeNode
////{
////    int val;
////    TreeNode* left;
////    TreeNode* right;
////    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
////};
////
////int maxDepth(TreeNode* root)
////{
////    if (nullptr == root)
////        return 0;
////
////    int l = 1 + maxDepth(root->left);
////    int r = 1 + maxDepth(root->right);
////
////    return l > r ? l : r;
////}
////
////void testMaxDepth()
////{
////    TreeNode* node1 = new TreeNode(3);
////    TreeNode* node2 = new TreeNode(9);
////    TreeNode* node3 = new TreeNode(20);
////    TreeNode* node4 = new TreeNode(15);
////    TreeNode* node5 = new TreeNode(7);
////
////    node1->left = node2;
////    node1->right = node3;
////    node3->left = node4;
////    node3->right = node5;
////
////    cout << maxDepth(node1) << endl;
////}
////
////int main()
////{
////    testMaxDepth();
////    system("pause");
////    return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//#include <algorithm>
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
//int maxDepth2(TreeNode* root)
//{
//    if (!root)
//        return 0;
//
//    return max(maxDepth2(root->left), maxDepth2(root->right)) + 1;
//}
//
//int maxDepth(TreeNode* root)
//{
//    if (!root)
//        return 0;
//
//    queue<TreeNode*> q;
//    q.emplace(root);
//    TreeNode* pCurrent = nullptr;
//    int res = 0;
//
//    while (!q.empty())
//    {
//        int len = q.size();
//
//        for (int i = 0; i < len; ++i)
//        {
//            pCurrent = q.front();
//            q.pop();
//
//            if (pCurrent->left)
//                q.emplace(pCurrent->left);
//
//            if (pCurrent->right)
//                q.emplace(pCurrent->right);
//        }
//
//        ++res;
//    }
//
//    return res;
//}
//
//TreeNode* createBinaryTree(const vector<string>& nums)
//{
//    if (nums.empty())
//        return nullptr;
//
//    TreeNode* root = new TreeNode(stoi(nums[0]));
//    queue<TreeNode*> q;
//    q.emplace(root);
//    TreeNode* pCurrent = nullptr;
//
//    int startIndex = 1;
//    int nextLevelIndex = 2;
//    int restIndex = nums.size() - 1;
//
//    while (restIndex > 0)
//    {
//        for (int i = startIndex; i < startIndex + nextLevelIndex; i += 2)
//        {
//            if (i >= nums.size())
//                return root;
//
//            pCurrent = q.front();
//            q.pop();
//            if (nums[i] != "null")
//            {
//                pCurrent->left = new TreeNode(stoi(nums[i]));
//                q.emplace(pCurrent->left);
//            }
//
//            if (i + 1 >= nums.size())
//                return root;
//
//            if (nums[i + 1] != "null")
//            {
//                pCurrent->right = new TreeNode(stoi(nums[i + 1]));
//                q.emplace(pCurrent->right);
//            }
//        }
//
//        startIndex += nextLevelIndex;
//        restIndex -= nextLevelIndex;
//        nextLevelIndex = q.size() * 2;
//    }
//
//    return root;
//}
//
//void testMaxDepth()
//{
//    vector<string> nums1 = { "3", "9", "20", "null", "null", "15", "7" };
//    auto root1 = createBinaryTree(nums1);
//    cout << maxDepth(root1) << endl;
//}
//
//int main()
//{
//    testMaxDepth();
//
//    getchar();
//    return 0;
//}