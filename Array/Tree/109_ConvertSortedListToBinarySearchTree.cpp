#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

TreeNode* sortedListToBST(ListNode* head, ListNode* tail)
{
    if (tail == head)
        return nullptr;

    if (head->next == tail)
    {
        TreeNode* root = new TreeNode(head->val);
        return root;
    }

    ListNode *mid = head, *temp = head;
    while (temp != tail && temp->next != tail)
    {
        mid = mid->next;
        temp = temp->next->next;
    }

    TreeNode *root = new TreeNode(mid->val);
    root->left = sortedListToBST(head, mid);
    root->right = sortedListToBST(mid->next, tail);

    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    if (nullptr == head)
        return nullptr;

    return sortedListToBST(head, nullptr);
}

TreeNode* sortedListToBST2(ListNode* head)
{
    if (nullptr == head)
        return nullptr;

    if (nullptr == head->next)
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
    root->left = sortedListToBST2(head);
    root->right = sortedListToBST2(slow->next);

    return root;
}

void displayList(ListNode* head)
{
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }

    cout << endl;
}

void inorderTraversal(TreeNode* root)
{
    if (nullptr == root)
        return;

    inorderTraversal(root->left);
    cout << root->val << endl;
    inorderTraversal(root->right);
}

void testSortedListToBST()
{
    //[-10, -3, 0, 5, 9]
    ListNode* head = new ListNode(-10);
    ListNode* node2 = new ListNode(-3);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(9);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    displayList(head);
    //auto result = sortedListToBST(head);
    auto result = sortedListToBST2(head);
    inorderTraversal(result);
}

int main()
{
    testSortedListToBST();
    system("pause");
    return 0;
}