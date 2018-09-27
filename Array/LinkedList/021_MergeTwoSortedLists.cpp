//#include <iostream>
//
//struct ListNode
//{
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
//{
//    ListNode preHead = ListNode(INT_MIN);
//    ListNode *p = &preHead;
//
//    while (l1 && l2)
//    {
//        if (l1->val <= l2->val)
//        {
//            p->next = new ListNode(l1->val);
//            l1 = l1 ? l1->next : l1;
//        }
//        else
//        {
//            p->next = new ListNode(l2->val);
//            l2 = l2 ? l2->next : l2;
//        }
//        p = p->next;
//    }
//
//    p->next = l1 ? l1 : l2;
//
//    return preHead.next;
//}
//
//void displayList(ListNode *head)
//{
//    while (head != nullptr)
//    {
//        std::cout << head->val << "->";
//        head = head->next;
//    }
//    std::cout << "NULL" << std::endl;
//}
//
//void testMergeTwoLists()
//{
//    ListNode *node1 = new ListNode(1);
//    ListNode *node2 = new ListNode(2);
//    ListNode *node3 = new ListNode(4);
//    ListNode *node4 = new ListNode(1);
//    ListNode *node5 = new ListNode(3);
//    ListNode *node6 = new ListNode(4);
//    node1->next = node2;
//    node2->next = node3;
//    node4->next = node5;
//    node5->next = node6;
//
//    displayList(node1);
//    displayList(node4);
//    displayList(mergeTwoLists(node1, node4));
//
//}
//
//int main()
//{
//    testMergeTwoLists();
//    system("pause");
//    return 0;
//}