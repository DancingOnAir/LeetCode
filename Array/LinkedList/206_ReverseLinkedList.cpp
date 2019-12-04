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
//ListNode* reverseList2(ListNode* head)
//{
//    if (!head || !head->next)
//        return head;
//    
//    ListNode* pre = nullptr;
//    ListNode* next = nullptr;
//
//    while (head)
//    {
//        next = head->next;
//        head->next = pre;
//
//        pre = head;
//        head = next;
//    }
//
//    return pre;
//}
//
//ListNode* reverseList(ListNode* head)
//{
//    if (!head || !head->next)
//        return head;
//
//    auto newHead = reverseList(head->next);
//    head->next->next = head;
//    head->next = nullptr;
//
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
//void testReverseList()
//{
//    ListNode *node1 = new ListNode(1);
//    ListNode *node2 = new ListNode(2);
//    ListNode *node3 = new ListNode(3);
//    ListNode *node4 = new ListNode(4);
//    ListNode *node5 = new ListNode(5);
//
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    auto res1 = reverseList(node1);
//    display(res1);
//}
//
//int main()
//{
//    testReverseList();
//
//    getchar();
//    return 0;
//}