#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
        return head;

    ListNode* preHead = new ListNode(0);
    preHead->next = head;
    ListNode* preNode, *curNode, *nextNode;

    preNode = curNode = preHead;
    while (curNode->next != nullptr && curNode->next->next != nullptr)
    {
        preNode = curNode;
        curNode = preNode->next;
        nextNode = curNode->next;

        curNode->next = nextNode->next;
        nextNode->next = preNode->next;
        preNode->next = nextNode;
    }

    return preHead->next;

    //ListNode* nextNode = head->next;
    //head->next = swapPairs(nextNode);
    //nextNode->next = head;

    //return nextNode;
}

void displayList(ListNode* head)
{
    while (head)
    {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
}

void testSwapPairs()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    displayList(node1);
    displayList(swapPairs(node1));
}

int main()
{
    testSwapPairs();
    system("pause");
    return 0;
}