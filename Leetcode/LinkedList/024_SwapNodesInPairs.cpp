////#include <iostream>
////
////struct ListNode
////{
////    int val;
////    ListNode *next;
////    ListNode(int x) : val(x), next(nullptr) {}
////};
////
////ListNode* swapPairs(ListNode* head)
////{
////    if (nullptr == head || nullptr == head->next)
////        return head;
////
////    ListNode* preHead = new ListNode(0);
////    preHead->next = head;
////    ListNode* preNode, *curNode, *nextNode;
////
////    preNode = curNode = preHead;
////    while (curNode->next != nullptr && curNode->next->next != nullptr)
////    {
////        preNode = curNode;
////        curNode = preNode->next;
////        nextNode = curNode->next;
////
////        curNode->next = nextNode->next;
////        nextNode->next = preNode->next;
////        preNode->next = nextNode;
////    }
////
////    return preHead->next;
////
////    //ListNode* nextNode = head->next;
////    //head->next = swapPairs(nextNode);
////    //nextNode->next = head;
////
////    //return nextNode;
////}
////
////void displayList(ListNode* head)
////{
////    while (head)
////    {
////        std::cout << head->val << ", ";
////        head = head->next;
////    }
////    std::cout << std::endl;
////}
////
////void testSwapPairs()
////{
////    ListNode *node1 = new ListNode(1);
////    ListNode *node2 = new ListNode(2);
////    ListNode *node3 = new ListNode(3);
////    ListNode *node4 = new ListNode(4);
////    node1->next = node2;
////    node2->next = node3;
////    node3->next = node4;
////
////    displayList(node1);
////    displayList(swapPairs(node1));
////}
////
////int main()
////{
////    testSwapPairs();
////    system("pause");
////    return 0;
////}
//
//#include <iostream>
//
//using namespace std;
//
//struct ListNode
//{
//    int val;
//    ListNode* next;
//    ListNode(int x): val(x), next(nullptr) {}
//};
//
//ListNode* reverse(ListNode* preHead)
//{
//
//    if (!preHead->next)
//        return preHead;
//    ListNode* p = preHead->next;
//
//    if (!p->next)
//        return preHead;
//    ListNode* q = p->next;
//
//    p->next = q->next;
//    q->next = p;
//
//    preHead->next = q;
//
//
//    return preHead;
//}
//
//ListNode* swapPairs2(ListNode* head)
//{
//    if (!head || !head->next)
//        return head;
//
//    ListNode preHead(0);
//    preHead.next = head;
//
//    ListNode *pre, *cur, *next;
//    pre = cur = &preHead;
//
//    while (cur->next && cur->next->next)
//    {
//        pre = cur;
//        cur = cur->next;
//        next = cur->next;
//
//        cur->next = next->next;
//        next->next = cur;
//        pre->next = next;
//    }
//
//    return preHead.next;
//}
//
//ListNode* reverseList(ListNode* head)
//{
//    if (head == nullptr || head->next == nullptr)
//        return head;
//
//    ListNode* tmp = reverseList(head->next);
//    head->next->next = head;
//    head->next = nullptr;
//
//    return tmp;
//}
//
//ListNode* reverseKGroup(ListNode* head, int k)
//{
//    ListNode* temp = head;
//    for (int i = 1; i < k && temp != nullptr; ++i)
//        temp = temp->next;
//
//    if (temp == nullptr)
//        return head;
//
//    ListNode* nextHead = temp->next;
//    temp->next = nullptr;
//
//    ListNode* newHead = reverseList(head);
//    ListNode* newTemp = reverseKGroup(nextHead, k);
//
//    head->next = newTemp;
//    return newHead;
//}
//
//ListNode* swapPairs(ListNode* head)
//{
//    return reverseKGroup(head, 2);
//}
//
//void display(ListNode* head)
//{
//    if (!head)
//    {
//        cout << endl;
//        return;
//    }
//
//    cout << head->val << "->";
//    display(head->next);
//}
//
//void testSwapPairs()
//{
//    ListNode *node1 = new ListNode(1);
//    ListNode *node2 = new ListNode(2);
//    ListNode *node3 = new ListNode(3);
//    ListNode *node4 = new ListNode(4);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//
//    display(node1);
//    display(swapPairs(node1));
//}
//
//int main()
//{
//    testSwapPairs();
//
//    getchar();
//    return 0;
//}