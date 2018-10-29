#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(std::vector<int>& nums)
{
    if (nums.empty())
        return nullptr;

    auto mid = nums.size() / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    
    std::vector<int> left_nums(nums.begin(), nums.begin() + mid);
    root->left = sortedArrayToBST(left_nums);

    std::vector<int> right_nums(nums.begin() + nums.size()/2 + 1, nums.end());
    root->right = sortedArrayToBST(right_nums);

    return root;
}

void display(TreeNode* root)
{
    if (nullptr == root)
        return;

    display(root->left);
    std::cout << root->val << std::endl;
    display(root->right);
}

void testSortedArrayToBST()
{
    std::vector<int> input = { -10, -3, 0, 5, 9 };
    auto result = sortedArrayToBST(input);
    display(result);
}

int main()
{
    testSortedArrayToBST();
    system("pause");
    return 0;
}