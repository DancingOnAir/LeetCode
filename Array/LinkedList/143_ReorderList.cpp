#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
        return head;

    ListNode *cur = head;
    ListNode *pre = nullptr;
    ListNode *next = nullptr;
    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

void reorderList(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
        return;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *head2 = reverseList(slow->next);
    slow->next = nullptr;
    ListNode *head1 = head;
    ListNode *cur;

    while (head2)
    {
        cur = head1->next;
        head1 = head1->next = head2;
        head2 = cur;
    }
}

void displayList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

void testReorderList()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    displayList(node1);
    reorderList(node1);
    displayList(node1);
}

int main()
{
    testReorderList();
    system("pause");
    return 0;
}
