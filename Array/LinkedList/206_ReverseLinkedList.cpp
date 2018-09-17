#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
        return head;

    ListNode *preNode = head;
    ListNode *currentNode = head->next;
    ListNode *nextNode;

    while (currentNode != nullptr)
    {
        nextNode = currentNode->next;
        currentNode->next = preNode;
        preNode = currentNode;
        currentNode = nextNode;
    }
    head->next = nullptr;

    return preNode;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

void testReverseList()
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

    printList(node1);
    
    printList(reverseList(node1));
}

int main()
{
    testReverseList();

    system("pause");
    return 0;
}