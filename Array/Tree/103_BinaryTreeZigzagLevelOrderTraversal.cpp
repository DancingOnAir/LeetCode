//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//vector<vector<int>> zigzagLevelOrder(TreeNode *root)
//{
//    vector<vector<int>> result;
//    if (nullptr == root)
//        return result;
//
//    queue<TreeNode*> q;
//    q.emplace(root);
//    TreeNode* cur = nullptr;
//    vector<int> vals;
//
//    while (!q.empty())
//    {
//        size_t  len = q.size();
//        for (size_t i = 0; i < len; ++i)
//        {
//            cur = q.front();
//            q.pop();
//
//            vals.emplace_back(cur->val);
//            if (cur->left)
//                q.emplace(cur->left);
//            if (cur->right)
//                q.emplace(cur->right);
//        }
//
//
//        result.emplace_back(vals);
//        vals.clear();
//    }
//
//    for (auto i = 0; i < result.size(); ++i)
//    {
//        if (i & 1)
//            reverse(result[i].begin(), result[i].end());
//    }
//
//    return result;
//}
//
//void display(vector<vector<int>>& input)
//{
//    if (input.empty())
//        return;
//
//    for (auto row : input)
//    {
//        for (auto col : row)
//            cout << col << ", ";
//        cout << endl;
//    }
//}
//
//void testZigzagLevelOrder()
//{
//    TreeNode* node1 = new TreeNode(3);
//    TreeNode* node2 = new TreeNode(9);
//    TreeNode* node3 = new TreeNode(20);
//    TreeNode* node4 = new TreeNode(15);
//    TreeNode* node5 = new TreeNode(7);
//
//    node1->left = node2;
//    node1->right = node3;
//    node3->left = node4;
//    node3->right = node5;
//
//    auto result = zigzagLevelOrder(node1);
//    display(result);
//}
//
//int main()
//{
//    testZigzagLevelOrder();
//    system("pause");
//    return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if (!root)
        return res;

    queue<TreeNode*> s;
    TreeNode* pCurrent = nullptr;
    s.emplace(root);
    bool level = true;

    while (!s.empty())
    {
        int len = s.size();
        vector<int> temp(len);
        for (int i = 0; i < len; ++i)
        {
            pCurrent = s.front();
            s.pop();
            
            if (level)
                temp[i] = pCurrent->val;
            else
                temp[len - i - 1] = pCurrent->val;

            if (pCurrent->left)
                s.emplace(pCurrent->left);
            if (pCurrent->right)
                s.emplace(pCurrent->right);
        }

        level = !level;
        res.emplace_back(temp);
    }

    return res;
}

TreeNode* createBinaryTree(const vector<string>& nums)
{
    if (nums.empty())
        return nullptr;

    TreeNode* root = new TreeNode(stoi(nums[0]));
    queue<TreeNode*> q;
    q.emplace(root);
    TreeNode* pCurrent = nullptr;

    int startIndex = 1;
    int nextLevelIndex = 2;
    int restIndex = nums.size() - 1;

    while (restIndex > 0)
    {
        for (int i = startIndex; i < startIndex + nextLevelIndex; i += 2)
        {
            if (i == nums.size())
                return root;

            pCurrent = q.front();
            q.pop();
            if (nums[i] != "null")
            {
                pCurrent->left = new TreeNode(stoi(nums[i]));
                q.emplace(pCurrent->left);
            }

            if (i + 1 == nums.size())
                return root;

            if (nums[i + 1] != "null")
            {
                pCurrent->right = new TreeNode(stoi(nums[i + 1]));
                q.emplace(pCurrent->right);
            }

            startIndex += nextLevelIndex;
            restIndex -= nextLevelIndex;
            nextLevelIndex = q.size() * 2;
        }
    }

    return root;
}

void display(const vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return;

    for (auto& row : matrix)
    {
        for (auto& col : row)
            cout << col << ", ";
        cout << endl;
    }
}

void testZigzagLevelOrder()
{
    vector<string> nums1 = { "3", "9" ,"20", "null", "null", "15", "7" };
    auto root1 = createBinaryTree(nums1);
    auto res1 = zigzagLevelOrder(root1);
    display(res1);
}

int main()
{
    testZigzagLevelOrder();

    getchar();
    return 0;
}