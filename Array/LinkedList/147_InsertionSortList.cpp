#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* insertionSortList(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
        return head;

    ListNode preHead = ListNode(INT_MIN);
    //preHead.next = head;

    auto cur = head;
    auto pre = &preHead;

    while (cur)
    {
        auto insertNode = cur;
        cur = cur->next;

        insertNode->next = nullptr;

        for (auto p = &preHead; p != nullptr; p = p->next)
        {
            if (p->next)
            {
                if (p->next->val >= insertNode->val)
                {
                    auto temp = p->next;
                    p->next = insertNode;
                    insertNode->next = temp;
                    break;
                }
            }
            else
            {
                p->next = insertNode;
                break;
            }

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

void testInsertionSortList()
{
    ListNode* node1 = new ListNode(6);
    ListNode* node2 = new ListNode(5);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(8);
    ListNode* node6 = new ListNode(7);
    ListNode* node7 = new ListNode(2);
    ListNode* node8 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;

    auto res1 = insertionSortList(node1);
    display(res1);
}

int main()
{
    testInsertionSortList();

    getchar();
    return 0;
}