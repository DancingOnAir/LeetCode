#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) 
{
    if (nullptr == head)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (slow  && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return true;
    }

    return false;
}

void testHasCycle()
{
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node4;

    bool status = hasCycle(head);
    std::cout << (status ? "has cycle" : "no cycle") << std::endl;
}

int main()
{
    testHasCycle();
    system("pause");
    return 0;
}