#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
{
    //if (0 == preorder.size() || preorder.size() != inorder.size())
    //    return nullptr;

    //
    //int p1 = 0;
    //int p2 = 0;
    //std::stack<TreeNode *> st;
    //TreeNode *root = new TreeNode(preorder[p1++]);
    //TreeNode *temp = root;
    //bool leftFlag = true;

    //while (p1 < preorder.size())
    //{
    //    if (leftFlag)
    //    {
    //        if (inorder[p2] == temp->val)
    //        {
    //            leftFlag = false;
    //            ++p2;
    //        }
    //        else
    //        {
    //            st.push(temp);
    //            temp = new TreeNode(preorder[p1++]);
    //            st.top()->left = temp;
    //        }
    //    }
    //    else
    //    {
    //        if (!st.empty() && st.top()->val == inorder[p2])
    //        {
    //            ++p2;
    //            temp = st.top();
    //            st.pop();
    //        }
    //        else
    //        {

    //        }
    //    }

    //    ++p1;
    //}

    //return root;

    if (0 == preorder.size() || preorder.size() != inorder.size())
        return nullptr;

    std::vector<int> pre_left, pre_right, in_left, in_right;
    TreeNode *head = new TreeNode(preorder[0]);

    int t;
    for (int i = 0; i < inorder.size(); i++) 
    {
        if (inorder[i] == preorder[0]) 
        {
            t = i;
            break;
        }
    }

    for (int i = 1; i <= t; i++) 
    {
        pre_left.push_back(preorder[i]);
    }

    for (int i = 0; i < t; i++) 
    {
        in_left.push_back(inorder[i]);
    }

    for (int i = t + 1; i < preorder.size(); i++) 
    {
        pre_right.push_back(preorder[i]);
    }

    for (int i = t + 1; i < preorder.size(); i++) 
    {
        in_right.push_back(inorder[i]);
    }

    head->left = buildTree(pre_left, in_left);
    head->right = buildTree(pre_right, in_right);

    return head;
}

void preorderTraverse(TreeNode *root)
{
    if (nullptr == root)
        return;

    std::cout << root->val << std::endl;
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

void preorderTraverse2(TreeNode *root)
{
    std::stack<TreeNode *> s;
    TreeNode *p = root;

    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            std::cout << p->val << std::endl;
            s.push(p);
            p = p->left;
        }

        if (!s.empty())
        {
            p = s.top()->right;
            s.pop();
        }
    }
}

void inorderTraverse(TreeNode *root)
{
    if (nullptr == root)
        return;

    std::stack<TreeNode *> s;
    TreeNode *p = root;

    while (!s.empty() || nullptr != p)
    {
        while (nullptr != p)
        {
            s.push(p);
            p = p->left;
        }

        if (!s.empty())
        {
            p = s.top();
            std::cout << p->val << std::endl;

            s.pop();
            p = p->right;
        }
    }
}

int main()
{
    std::vector<int> preorder = { 3,9,20,15,7 };
    std::vector<int> inorder = { 9,3,15,20,7 };
    TreeNode *root = buildTree(preorder, inorder);
    inorderTraverse(root);

    system("pause");
    return 0;
}