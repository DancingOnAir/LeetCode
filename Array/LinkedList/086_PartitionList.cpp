#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* partition(ListNode* head, int x)
{
    if (!head || head->next == nullptr)
        return head;

    ListNode preHead = ListNode(0);
    preHead.next = head;

    ListNode* pre = &preHead;
    ListNode* cur = &preHead;

    while (cur->next)
    {
        if (cur->next->val < x && pre->next->val < x)
        {
            cur = cur->next;
            pre = pre->next;
        }
        else if (cur->next->val >= x && pre->next->val >= x)
        {
            cur = cur->next;
        }
        else if (cur->next->val < x && pre->next->val >= x)
        {
            auto tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;

            pre = pre->next;
        }
    }

    return preHead.next;
}

void display(ListNode* head)
{
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }

    cout << endl;
}

void testPartition()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    auto res1 = partition(node1, 3);
    display(res1);
}

int main()
{
    testPartition();

    getchar();
    return 0;
}