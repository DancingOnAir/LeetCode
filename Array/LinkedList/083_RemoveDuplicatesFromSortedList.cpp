#include <iostream>
#include <cstdlib>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
        return head;

    ListNode* p = head->next;
    ListNode* pre = head;

    while (p != nullptr)
    {
        if (pre->val == p->val)
        {
            while (p != nullptr && p->val == pre->val)
            {
                p = p->next;
            }

            pre->next = p;

            if (nullptr == p)
                return head;
        }

        p = p->next;
        pre = pre->next;
    }

    return head;
}

void display(ListNode* head)
{
    if (nullptr == head)
        return;

    ListNode* p = head;

    while (p != nullptr)
    {
        std::cout << p->val << "->";
        p = p->next;
    }

    std::cout << "NULL" << std::endl;
}

int main()
{
    ListNode a(1), b(2), c(2), d(2), e(2);
    ListNode* p;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    p = &a;
    
    display(p);
    display(deleteDuplicates(p));

    system("pause");
    return 0;
}