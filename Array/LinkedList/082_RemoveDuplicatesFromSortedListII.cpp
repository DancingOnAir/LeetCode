////#include <iostream>
////#include <cstdlib>
////
////struct ListNode
////{
////    int val;
////    ListNode* next;
////    ListNode(int x) : val(x), next(nullptr) {}
////};
////
////ListNode* deleteDuplicates(ListNode* head)
////{
////    //if (nullptr == head || nullptr == head->next)
////    //    return head;
////
////    //ListNode* currentNode = head;
////    //ListNode* preNode = new ListNode(0);
////    //preNode->next = head;
////
////    //ListNode* nextNode = head->next;
////
////    //while (currentNode != nullptr)
////    //{
////    //    if (nullptr == nextNode)
////    //        return currentNode;
////
////    //    if (currentNode->val == nextNode->val)
////    //    {
////    //        while (nextNode != nullptr && currentNode->val == nextNode->val)
////    //        {
////    //            nextNode = nextNode->next;
////    //        }
////
////    //        if (nullptr == nextNode)
////    //        {
////    //            preNode->next = nullptr;
////    //            return preNode;
////    //        }
////    //        else
////    //        {
////    //            preNode->next = nextNode;
////    //            currentNode = nextNode;
////    //            nextNode = nextNode->next;
////    //        }
////    //    }
////    //    else
////    //    {
////    //        preNode = preNode->next;
////    //        currentNode = currentNode->next;
////    //        nextNode = nextNode->next;
////    //    }
////    //}
////
////    //return head;
////
////    ListNode* pre = new ListNode(0);
////    pre->next = head;
////
////    ListNode* current = head;
////    ListNode* p = pre;
////
////    while (current != nullptr)
////    {
////        bool isDuplicated = false;
////
////        while (current->next != nullptr && current->next->val == current->val)
////        {
////            isDuplicated = true;
////            current = current->next;
////        }
////
////        if (isDuplicated)
////        {
////            current = current->next;
////            p->next = nullptr;
////        }
////        else
////        {
////            p->next = current;
////            current = current->next;
////            p = p->next;
////        }
////    }
////
////    return pre->next;
////}
////
////void display(ListNode* head)
////{
////    if (nullptr == head)
////        return;
////
////    ListNode* p = head;
////
////    while (p != nullptr)
////    {
////        std::cout << p->val << "->";
////        p = p->next;
////    }
////
////    std::cout << "NULL" << std::endl;
////}
////
////int main()
////{
////    ListNode a(1), b(2), c(2), d(3), e(3);
////    ListNode* p;
////
////    a.next = &b;
////    b.next = &c;
////    c.next = &d;
////    d.next = &e;
////    p = &a;
////    
////    display(p);
////    display(deleteDuplicates(p));
////
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
//ListNode* deleteDuplicates(ListNode* head)
//{
//    if (!head || !head->next)
//        return head;
//
//    ListNode preHead = ListNode(0);
//    preHead.next = head;
//
//    ListNode* slow = &preHead;
//    ListNode* fast = head;
//
//    while (fast)
//    {
//        bool isDuplicate = false;
//        while (fast->next && fast->val == fast->next->val)
//        {
//            isDuplicate = true;
//            fast = fast->next;
//        }
//
//        if (isDuplicate)
//        {
//            fast = fast->next;
//            slow->next = fast;
//        }
//        else
//        {
//            slow->next = fast;
//            slow = slow->next;
//            fast = fast->next;
//        }
//    }
//
//    return preHead.next;
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
//void testDeleteDuplicate()
//{
//    ListNode* node1 = new ListNode(1);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node3 = new ListNode(3);
//    ListNode* node4 = new ListNode(3);
//    ListNode* node5 = new ListNode(4);
//    ListNode* node6 = new ListNode(4);
//    ListNode* node7 = new ListNode(5);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
//    auto res1 = deleteDuplicates(node1);
//    display(res1);
//}
//
//int main()
//{
//    testDeleteDuplicate();
//
//    getchar();
//    return 0;
//}