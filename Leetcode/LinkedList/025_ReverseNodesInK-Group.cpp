////#include <iostream>
////
////struct ListNode
////{
////    int val;
////    ListNode *next;
////    ListNode(int x) : val(x), next(nullptr) {}
////};
////
////ListNode* reverseList(ListNode *head)
////{
////    if (nullptr == head || nullptr == head->next)
////        return head;
////
////    ListNode *pre = nullptr, *next = nullptr, *cur = head;
////    while (cur != nullptr)
////    {
////        next = cur->next;
////        cur->next = pre;
////        pre = cur;
////        cur = next;
////    }
////
////    return pre;
////}
////
////ListNode* reverseKGroup(ListNode* head, int k)
////{
////    if (nullptr == head || k < 1)
////        return head;
////
////    int count = 0;
////    ListNode preHead(INT_MIN);
////    ListNode *p = &preHead;
////    p->next = head;
////
////    ListNode *cur = head;
////    ListNode *next = nullptr;
////    ListNode *pre = head;
////    while (cur != nullptr)
////    {
////        ++count;
////        if (0 == count % k)
////        {
////            next = cur->next;
////            cur->next = nullptr;
////
////            p->next = reverseList(pre);
////            while (p->next)
////                p = p->next;
////
////            pre = cur = next;
////        }
////        else
////        {
////            cur = cur->next;
////        }
////    }
////
////    if (next)
////        p->next = next;
////
////    return preHead.next;
////
////}
////
////void displayList(ListNode *head)
////{
////    while (head != nullptr)
////    {
////        std::cout << head->val << "->";
////        head = head->next;
////    }
////    std::cout << "NULL" << std::endl;
////}
////
////void testReverseKGroup()
////{
////    ListNode *node1 = new ListNode(1);
////    ListNode *node2 = new ListNode(2);
////    ListNode *node3 = new ListNode(3);
////    ListNode *node4 = new ListNode(4);
////    ListNode *node5 = new ListNode(5);
////    ListNode *node6 = new ListNode(6);
////    node1->next = node2;
////    node2->next = node3;
////    node3->next = node4;
////    node4->next = node5;
////    node5->next = node6;
////
////    displayList(node1);
////    displayList(reverseKGroup(node1, 2));
////}
////
////int main()
////{
////    testReverseKGroup();
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
//ListNode* reverseList(ListNode* head)
//{
//    if (!head || !head->next)
//        return head;
//
//    ListNode* temp = reverseList(head->next);
//    head->next->next = head;
//    head->next = nullptr;
//
//    return temp;
//}
//
//ListNode* reverseKGroup(ListNode* head, int k)
//{
//    if (k < 2)
//        return head;
//
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
//    ListNode* nextTemp = reverseKGroup(nextHead, k);
//
//    head->next = nextTemp;
//    return newHead;
//}
//
//void display(ListNode* head)
//{
//    while (head)
//    {
//        cout << head->val << "->";
//        head = head->next;
//    }
//
//    cout << endl;
//}
//
//void testReverseKGroup()
//{
//    ListNode *node1 = new ListNode(1);
//    ListNode *node2 = new ListNode(2);
//    ListNode *node3 = new ListNode(3);
//    ListNode *node4 = new ListNode(4);
//    ListNode *node5 = new ListNode(5);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//
//    display(node1);
//    //display(reverseKGroup(node1, 2));
//    display(reverseKGroup(node1, 3));
//}
//
//int main()
//{
//    testReverseKGroup();
//
//    getchar();
//    return 0;
//}