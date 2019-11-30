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
//ListNode* insertionSortList(ListNode* head)
//{
//    if (nullptr == head || nullptr == head->next)
//        return head;
//
//    ListNode preHead = ListNode(INT_MIN);
//    ListNode* cur = head;
//    ListNode* pre = &preHead;
//    ListNode* next = nullptr;
//
//    while (cur)
//    {
//        next = cur->next;
//        if (!pre->next || pre->next->val > cur->val)
//            pre = &preHead;
//        while (pre->next && pre->next->val <= cur->val)
//            pre = pre->next;
//
//        cur->next = pre->next;
//        pre->next = cur;
//
//        cur = next;
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
//void testInsertionSortList()
//{
//    ListNode* node1 = new ListNode(6);
//    ListNode* node2 = new ListNode(5);
//    ListNode* node3 = new ListNode(3);
//    ListNode* node4 = new ListNode(1);
//    ListNode* node5 = new ListNode(8);
//    ListNode* node6 = new ListNode(7);
//    ListNode* node7 = new ListNode(2);
//    ListNode* node8 = new ListNode(4);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
//    node7->next = node8;
//
//    auto res1 = insertionSortList(node1);
//    display(res1);
//}
//
//int main()
//{
//    testInsertionSortList();
//
//    getchar();
//    return 0;
//}