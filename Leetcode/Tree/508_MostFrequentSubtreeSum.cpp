//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//struct TreeNode
//{
//    TreeNode* left;
//    TreeNode* right;
//    int val;
//
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
//    {
//
//    }
//};
//
//int getSum(TreeNode* root, unordered_map<int, int>& counts, int& maxCount)
//{
//    if (!root)
//        return 0;
//
//    int sum = root->val;
//    sum += getSum(root->left, counts, maxCount);
//    sum += getSum(root->right, counts, maxCount);
//
//    ++counts[sum];
//    maxCount = maxCount > counts[sum] ? maxCount : counts[sum];
//
//    return sum;
//}
//
//vector<int> findFrequentTreeSum(TreeNode* root)
//{
//    unordered_map<int, int> counts;
//    int maxCount = INT_MIN;
//    vector<int> res;
//    getSum(root, counts, maxCount);
//
//    for (auto& x : counts)
//    {
//        if (x.second == maxCount)
//            res.emplace_back(x.first);
//    }
//
//    return res;
//}
//
//int pindex = 0;
//TreeNode* generateBinaryTree(const vector<string>& bt)
//{
//    if (bt[pindex] == "null")
//    {
//        ++pindex;
//        return nullptr;
//    }
//
//    TreeNode* root = new TreeNode(stoi(bt[pindex++]));
//    root->left = generateBinaryTree(bt);
//    root->right = generateBinaryTree(bt);
//
//    return root;
//}
//
//void display(const vector<int>& nums)
//{
//    for (int x : nums)
//        cout << x << ", ";
//    cout << endl;
//}
//
//void testFindFrequentTreeSum()
//{
//    vector<string> bt1 = { "5", "2", "-3", "null", "null", "null", "null" };
//    auto root1 = generateBinaryTree(bt1);
//    auto res1 = findFrequentTreeSum(root1);
//    display(res1);
//
//    vector<string> bt2 = { "5", "2", "-5" };
//    auto root2 = generateBinaryTree(bt2);
//    auto res2 = findFrequentTreeSum(root2);
//    display(res2);
//}
//
//int main()
//{
//    testFindFrequentTreeSum();
//
//    getchar();
//    return 0;
//}