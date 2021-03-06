////#include <iostream>
////
////struct ListNode
////{
////    int val;
////    ListNode *next;
////    ListNode(int x) : val(x), next(nullptr) {}
////};
////
////ListNode* removeElements(ListNode* head, int val)
////{
////    if (nullptr == head)
////        return head;
////
////    ListNode preHead(0);
////    ListNode *p = head;
////    ListNode *q = &preHead;
////    q->next = head;
////
////    while (p != nullptr)
////    {
////        if (val == p->val)
////        {
////            ListNode *toBeDelete = p;
////            q->next = p->next;
////            p = q->next;
////            delete toBeDelete;
////        }
////        else
////        {
////            p = p->next;
////            q = q->next;
////        }
////    }
////
////    return preHead.next;
////}
////
////void displayList(ListNode *head)
////{
////    while (head)
////    {
////        std::cout << head->val << "->";
////        head = head->next;
////    }
////
////    std::cout << "NULL" <<  std::endl;
////}
////
////void testRemoveElements()
////{
////    ListNode *node1 = new ListNode(1);
////    ListNode *node2 = new ListNode(2);
////    ListNode *node3 = new ListNode(6);
////    ListNode *node4 = new ListNode(3);
////    ListNode *node5 = new ListNode(4);
////    ListNode *node6 = new ListNode(5);
////    ListNode *node7 = new ListNode(6);
////    node1->next = node2;
////    node2->next = node3;
////    node3->next = node4;
////    node4->next = node5;
////    node5->next = node6;
////    node6->next = node7;
////    displayList(node1);
////    displayList(removeElements(node1, 6));
////
////}
////
////int main()
////{
////    testRemoveElements();
////    system("pause");
////    return 0;
////}
//
//#include <iostream>
//using namespace std;
//
//struct ListNode
//{
//    int val;
//    ListNode* next;
//    ListNode(int x): val(x), next(nullptr) {}
//};
//
//ListNode* removeElements2(ListNode* head, int val)
//{
//    if (!head)
//        return nullptr;
//
//    ListNode preHead = ListNode(0);
//    preHead.next = head;
//
//    auto pre = &preHead;
//    auto cur = head;
//
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            pre->next = cur->next;
//        }
//        else
//        {
//            pre = pre->next;
//        }
//        cur = cur->next;
//    }
//
//    return preHead.next;
//}
//
//ListNode* removeElements(ListNode* head, int val)
//{
//    if (!head)
//        return nullptr;
//
//    ListNode** cur = &head;
//
//    while (*cur)
//    {
//        if ((*cur)->val == val)
//            *cur = (*cur)->next;
//        else
//            cur = &(*cur)->next;
//    }
//
//    return head;
//}
//
//void display(ListNode* head)
//{
//    while (head)
//    {
//        cout << head->val << "->";
//        head = head->next;
//    }
//    cout << endl;
//}
//
//void testRemoveElements()
//{
//    ListNode *head1 = new ListNode(1);
//    ListNode *node2 = new ListNode(2);
//    ListNode *node3 = new ListNode(6);
//    ListNode *node4 = new ListNode(3);
//    ListNode *node5 = new ListNode(4);
//    ListNode *node6 = new ListNode(5);
//    ListNode *node7 = new ListNode(6);
//
//    head1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
//
//    auto res1 = removeElements(head1, 6);
//    display(res1);
//}
//
//int main()
//{
//    testRemoveElements();
//
//    getchar();
//    return 0;
//}