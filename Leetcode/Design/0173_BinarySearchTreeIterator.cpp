#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

//class BSTIterator {
//public:
//    BSTIterator(TreeNode* root): curIndex(0), root_(root)
//    {
//        inorderTraversal(root_, nums_);
//    }
//
//    /** @return the next smallest number */
//    int next()
//    {
//        if (hasNext())
//            return nums_[curIndex++];
//
//        return -1;
//    }
//
//    /** @return whether we have a next smallest number */
//    bool hasNext()
//    {
//        return curIndex < nums_.size();
//    }
//
//    void inorderTraversal(TreeNode* root, std::vector<int>& nums)
//    {
//        if (!root)
//            return;
//
//        inorderTraversal(root->left, nums);
//        nums.emplace_back(root->val);
//        inorderTraversal(root->right, nums);
//    }
//
//private:
//    TreeNode* root_;
//    std::vector<int> nums_;
//    int curIndex;
//};

//class BSTIterator {
//public:
//    BSTIterator(TreeNode* root)
//    {
//        pushTreeNode(root);
//    }
//
//    /** @return the next smallest number */
//    int next()
//    {
//        auto temp = stk.top();
//        stk.pop();
//        pushTreeNode(temp->right);
//
//        return temp->val;
//    }
//
//    /** @return whether we have a next smallest number */
//    bool hasNext()
//    {
//        return !stk.empty();
//    }
//
//    void pushTreeNode(TreeNode* root)
//    {
//        for (; root != nullptr; root = root->left)
//            stk.emplace(root);
//    }
//
//private:
//    std::stack<TreeNode*> stk;
//};
//
//TreeNode* createBinaryTree(const std::vector<std::string>& nums)
//{
//    if (nums.empty())
//        return nullptr;
//
//    auto root = new TreeNode(std::stoi(nums[0]));
//    std::queue<TreeNode*> q;
//    q.emplace(root);
//    TreeNode* pCur = nullptr;
//
//    int startIndex = 1;
//    int nextLevelIndex = 2;
//    int restIndex = nums.size() - 1;
//
//    while (restIndex > 0)
//    {
//        for (int i = startIndex; i < startIndex + nextLevelIndex; i += 2)
//        {
//            if (i > nums.size())
//                return root;
//
//            pCur = q.front();
//            q.pop();
//
//            if (nums[i] != "null")
//            {
//                pCur->left = new TreeNode(std::stoi(nums[i]));
//                q.emplace(pCur->left);
//            }
//
//            if (i + 1 > nums.size())
//                return root;
//
//            if (nums[i + 1] != "null")
//            {
//                pCur->right = new TreeNode(std::stoi(nums[i + 1]));
//                q.emplace(pCur->right);
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
//void test()
//{
//
//    std::vector<std::string> nums = { "7", "3", "15", "null", "null", "9", "20" };
//    TreeNode* root = createBinaryTree(nums);
//
//    BSTIterator iterator = BSTIterator(root);
//    std::cout << iterator.next() << std::endl;    // return 3
//    std::cout << iterator.next() << std::endl;    // return 7
//    std::cout << (iterator.hasNext() ? "True" : "False") << std::endl; // return true
//    std::cout << iterator.next() << std::endl;    // return 9
//    std::cout << (iterator.hasNext() ? "True" : "False") << std::endl; // return true
//    std::cout << iterator.next() << std::endl;    // return 15
//    std::cout << (iterator.hasNext() ? "True" : "False") << std::endl; // return true
//    std::cout << iterator.next() << std::endl;    // return 20
//    std::cout << (iterator.hasNext() ? "True" : "False") << std::endl; // return false
//}
//
//int main()
//{
//    test();
//
//    getchar();
//    return 0;
//}