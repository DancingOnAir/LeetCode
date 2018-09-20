#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode *head)
{
    if (nullptr == head || nullptr == head->next)
        return head;

    ListNode *oddNode, *evenNode, *oddTail, *evenHead;
    oddNode = head;
    evenHead = evenNode = head->next;

    while (oddNode && evenNode)
    {
        if (oddNode->next)
        {
            oddTail = oddNode;
            oddNode->next = oddNode->next->next;
            oddNode = oddNode->next;
        }

        if (evenNode->next)
        {
            evenNode->next = evenNode->next->next;
            evenNode = evenNode->next;
        }
    }

    if (oddNode)
        oddNode->next = evenHead;
    else
        oddTail->next = evenHead;

    return head;
}

ListNode* oddEvenList2(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
        return head;

    ListNode *oddNode(head), *evenNode(head->next), *evenHead = evenNode;
    while (evenNode && evenNode->next)
    {
        oddNode->next = oddNode->next->next;
        evenNode->next = evenNode->next->next;
        oddNode = oddNode->next;
        evenNode = evenNode->next;
    }

    oddNode->next = evenHead;
    return head;
}

void displayList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << "->";
        head = head->next;
    }

    std::cout << "NULL" << std::endl;
}

void testOddEvenList()
{
    //Input: 1->2->3->4->5->NULL
    //Output : 1->3->5->2->4->NULL
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
    displayList(oddEvenList2(node1));
}

int main()
{
    testOddEvenList();
    system("pause");
    return 0;
}