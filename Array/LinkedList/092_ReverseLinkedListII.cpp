#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode *head, ListNode *pre2)
{
    ListNode *cur = head;
    while (cur != nullptr)
    {
        ListNode *p = cur->next;
        cur->next = pre2;
        pre2 = cur;
        cur = p;
    }

    return pre2;
}

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if (nullptr == head || m >= n || n < 1)
        return head;

    ListNode *pre1 = nullptr;
    ListNode *cur = head;
    int count = 1;
    while (cur != nullptr)
    {
        if (count == m)
        {
            while (count != n)
            {
                cur = cur->next;
                ++count;
            }
            break;
        }
        else
        {
            pre1 = cur;
            cur = cur->next;

        }
        
        ++count;
    }

    ListNode *pre2 = cur->next;
    cur->next = nullptr;
    if (nullptr == pre1->next)
        return reverse(head, pre2);

    pre1->next = reverse(pre1->next, pre2);
    return head;
}

void displayList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << "->";
        head = head->next;
    }

    std::cout << "NULL" <<  std::endl;
}

void testReverseBetween()
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
    displayList(reverseBetween(node1, 2, 4));
}

int main()
{
    testReverseBetween();

    system("pause");
    return 0;
}