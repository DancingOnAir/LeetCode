////#include <iostream>
////#include <vector>
////#include <queue>
////
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
////vector<vector<int>> levelOrderBottom(TreeNode *root)
////{
////    vector<vector<int>> result;
////    if (nullptr == root)
////        return result;
////
////    queue<TreeNode*> q;
////    q.emplace(root);
////    TreeNode* cur = nullptr;
////    vector<int> vals;
////
////    while (!q.empty())
////    {
////        size_t  len = q.size();
////        for (size_t i = 0; i < len; ++i)
////        {
////            cur = q.front();
////            q.pop();
////
////            vals.emplace_back(cur->val);
////            if (cur->left)
////                q.emplace(cur->left);
////            if (cur->right)
////                q.emplace(cur->right);
////        }
////
////
////        result.emplace_back(vals);
////        vals.clear();
////    }
////
////    std::reverse(result.begin(), result.end());
////
////    return result;
////}
////
////void display(vector<vector<int>>& input)
////{
////    if (input.empty())
////        return;
////
////    for (auto row : input)
////    {
////        for (auto col : row)
////            cout << col << ", ";
////        cout << endl;
////    }
////}
////
////void testLevelOrderBottom()
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
////    auto result = levelOrderBottom(node1);
////    display(result);
////}
////
////int main()
////{
////    testLevelOrderBottom();
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
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
//    {
//
//    }
//};
//
//int getMaxDepth(TreeNode* root)
//{
//    if (!root)
//        return 0;
//
//    return max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1;
//}
//
//vector<vector<int>> levelOrderBottom(TreeNode* root)
//{
//    int depth = getMaxDepth(root);
//    vector<vector<int>> res(depth, vector<int>());
//
//    queue<TreeNode*> q;
//    q.emplace(root);
//    TreeNode* pCurrent = nullptr;
//
//    for (int j = depth - 1; j >= 0; --j)
//    {
//        int len = q.size();
//        vector<int> temp(len);
//        for (int i = 0; i < len; ++i)
//        {
//            pCurrent = q.front();
//            q.pop();
//            temp[i] = pCurrent->val;
//
//            if (pCurrent->left)
//                q.emplace(pCurrent->left);
//            if (pCurrent->right)
//                q.emplace(pCurrent->right);
//        }
//        res[j].assign(temp.begin(), temp.end());
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
//void display(const vector<vector<int>>& matrix)
//{
//    for (auto& row : matrix)
//    {
//        for (auto& col : row)
//            cout << col << ", ";
//        cout << endl;
//    }
//}
//
//void testLevelOrderBottom()
//{
//    vector<string> nums = { "3", "9", "20", "null", "null", "15", "7" };
//    TreeNode* root = createBinaryTree(nums);
//    auto res = levelOrderBottom(root);
//    display(res);
//}
//
//int main()
//{
//    testLevelOrderBottom();
//
//    getchar();
//    return 0;
//}