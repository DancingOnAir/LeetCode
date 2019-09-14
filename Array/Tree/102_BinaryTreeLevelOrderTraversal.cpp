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
//vector<vector<int>> levelOrder(TreeNode* root)
//{
//    vector<vector<int>> res;
//    if (!root)
//        return res;
//
//    queue<TreeNode*> q;
//    q.emplace(root);
//    TreeNode* pCurrent = nullptr;
//
//    while (!q.empty())
//    {
//        vector<int> nums;
//        int s = q.size();
//        while (s > 0)
//        {
//            pCurrent = q.front();
//            q.pop();
//            nums.emplace_back(pCurrent->val);
//
//            if (pCurrent->left)
//                q.emplace(pCurrent->left);
//
//            if (pCurrent->right)
//                q.emplace(pCurrent->right);
//
//            --s;
//        }
//
//        res.emplace_back(nums);
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
//
//    TreeNode* pCurrent = nullptr;
//
//    int startIndex = 1;
//    int restIndex = nums.size() - 1;
//    int nextLevelIndex = 2;
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
//void display(vector<vector<int>>& matrix)
//{
//    for (auto& row : matrix)
//    {
//        for (auto& col : row)
//            cout << col << ", ";
//        cout << endl;
//    }
//}
//
//void testLevelOrder()
//{
//    vector<string> nums1 = { "3", "9", "20", "null", "null", "15", "7" };
//    TreeNode* root1 = createBinaryTree(nums1);
//    auto res1 = levelOrder(root1);
//    display(res1);
//
//}
//
//int main()
//{
//    testLevelOrder();
//
//    getchar();
//    return 0;
//}