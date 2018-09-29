//#include <iostream>
//
//struct ListNode
//{
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//ListNode* mergeList(ListNode* l1, ListNode* l2)
//{
//    ListNode preHead(INT_MIN);
//    ListNode *p = &preHead;
//    
//    while (l1 != nullptr && l2 != nullptr)
//    {
//        if (l1->val < l2->val)
//        {
//            p->next = l1;
//            l1 = l1 ? l1->next : l1;
//        }
//        else
//        {
//            p->next = l2;
//            l2 = l2 ? l2->next : l2;
//        }
//        
//        p = p->next;
//    }
//
//    p->next = l1 ? l1 : l2;
//    return preHead.next;
//}
//
//ListNode* sortList(ListNode* head)
//{
//    if (nullptr == head || nullptr == head->next)
//        return head;
//
//    ListNode *slow = head, *fast = head;
//    while (fast->next != nullptr && fast->next->next != nullptr)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    fast = slow->next;
//    slow->next = nullptr;
//
//    return mergeList(sortList(head), sortList(fast));
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
//void testSortList()
//{
//    ListNode *node1 = new ListNode(-1);
//    ListNode *node2 = new ListNode(5);
//    ListNode *node3 = new ListNode(3);
//    ListNode *node4 = new ListNode(4);
//    ListNode *node5 = new ListNode(0);
//
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    
//    displayList(node1);
//    displayList(sortList(node1));
//}
//
//int main()
//{
//    testSortList();
//    system("pause");
//    return 0;
//}