#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    if (nullptr == headA || nullptr == headB)
        return nullptr;

    ListNode *p1 = headA;
    ListNode *p2 = headB;
    int m = 0, n = 0;

    while (p1 != nullptr || p2 != nullptr)
    {
        if (p1 != nullptr && p2 != nullptr)
        {
            ++m;
            ++n;

            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 == nullptr && p2 != nullptr)
        {
            ++n;

            p2 = p2->next;
        }

        if (p1 != nullptr && p2 == nullptr)
        {
            ++m;
            p1 = p1->next;
        }
    }

    int diff = std::abs(m - n);
    p1 = headA;
    p2 = headB;
    if (0 == diff)
    {
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1 == p2)
                return p1;

            p1 = p1->next;
            p2 = p2->next;
        }

        return nullptr;
    }
    else
    {
        if (m > n)
        {
            while (diff--)
                p1 = p1->next;
        }
        else
        {
            while (diff--)
                p2 = p2->next;
        }

        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1 == p2)
                return p1;

            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
}

void testIntersectionNode()
{
    ListNode *headA = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    ListNode *headB = new ListNode(6);
    ListNode *node7 = new ListNode(7);
    ListNode *node8 = new ListNode(8);

    headA->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    headB->next = node7;
    node7->next = node8;
    node8->next = node3;

    ListNode* result = getIntersectionNode(headA, headB);
    std::cout << result->val << std::endl;
}

int main()
{
    testIntersectionNode();

    system("pause");
    return 0;
}