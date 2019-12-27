////#include <iostream>
////
////struct TreeNode
////{
////    int val;
////    TreeNode* left;
////    TreeNode* right;
////    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
////};
////
////bool helper(TreeNode* p, TreeNode* q)
////{
////    if (nullptr == p || nullptr == q)
////        return p == q;
////
////    return (p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left));
////}
////
////bool isSymmetric(TreeNode* root)
////{
////    if (nullptr == root || (nullptr == root->left && nullptr == root->right))
////        return true;
////
////    return helper(root->left, root->right);
////}
////
////void testIsSymmetric()
////{
////    TreeNode* node1 = new TreeNode(1);
////    TreeNode* node2 = new TreeNode(2);
////    TreeNode* node3 = new TreeNode(2);
////    TreeNode* node4 = new TreeNode(3);
////    TreeNode* node5 = new TreeNode(4);
////    TreeNode* node6 = new TreeNode(2);
////    TreeNode* node7 = new TreeNode(3);
////
////    node1->left = node2;
////    node1->right = node3;
////    node2->left = node4;
////    node2->right = node5;
////    node3->left = node6;
////    node3->right = node7;
////
////    auto result = isSymmetric(node1);
////    std::cout << result << std::endl;
////}
////
////int main()
////{
////    testIsSymmetric();
////    system("pause");
////    return 0;
////}
//
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
//    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//};
//
//bool helper(TreeNode* left, TreeNode* right)
//{
//    if (!left || !right)
//        return left == right;
//
//    return (left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left));
//}
//
//bool isSymmetric(TreeNode* root)
//{
//    if (!root)
//        return true;
//
//    if (!(root->left) && !(root->right))
//        return true;
//
//    return helper(root->left, root->right);
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
//void testIsSymmetric()
//{
//    //vector<string> nums1 = { "1","2","2","3","4","4","3" };
//    //auto root1 = createBinaryTree(nums1);
//    //cout << (isSymmetric(root1) ? "True" : "False") << endl;
//
//    //vector<string> nums2 = { "1","2","2","null","3","null","3" };
//    //auto root2 = createBinaryTree(nums2);
//    //cout << (isSymmetric(root2) ? "True" : "False") << endl;
//
//    vector<string> nums3 = { "1","null","2" };
//    auto root3 = createBinaryTree(nums3);
//    cout << (isSymmetric(root3) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testIsSymmetric();
//
//    getchar();
//    return 0;
//}