#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedListToBST(ListNode* head)
{
    if (!head)
        return nullptr;

    if (head->next == nullptr)
        return new TreeNode(head->val);

    ListNode *pre = head, *slow = head, *fast = head;
    while (fast && fast->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}

void inorderTraversal(TreeNode* root)
{
    if (!root)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << endl;
    inorderTraversal(root->right);
}

void testSortedListToBST()
{
    ListNode *node1 = new ListNode(-10);
    ListNode *node2 = new ListNode(-3);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(9);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    auto res1 = sortedListToBST(node1);
    inorderTraversal(res1);
}

int main()
{
    testSortedListToBST();

    getchar();
    return 0;
}