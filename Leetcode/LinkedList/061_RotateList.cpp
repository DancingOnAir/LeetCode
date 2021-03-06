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
//ListNode* rotateRight(ListNode* head, int k)
//{
//    if (!head || head->next == nullptr || !k)
//        return head;
//
//    ListNode* p = head;
//    ListNode* q = head;
//    int len = 0;
//
//    while (p)
//    {
//        ++len;
//        p = p->next;
//    }
//    p = head;
//
//    k %= len;
//    if (!k)
//        return head;
//    
//    while (k--)
//        q = q->next;
//
//    while (q->next != nullptr)
//    {
//        p = p->next;
//        q = q->next;
//    }
//
//    q->next = head;
//    head = p->next;
//    p->next = nullptr;
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
//
//    cout << endl;
//}
//
//void testRotateRight()
//{
//    ListNode* node1 = new ListNode(1);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node3 = new ListNode(3);
//    ListNode* node4 = new ListNode(4);
//    ListNode* node5 = new ListNode(5);
//    node1->next = node2;
//    //node2->next = node3;
//    //node3->next = node4;
//    //node4->next = node5;
//    auto res1 = rotateRight(node1, 1);
//    display(res1);
//
//    ListNode* node6 = new ListNode(0);
//    ListNode* node7 = new ListNode(1);
//    ListNode* node8 = new ListNode(2);
//    node6->next = node7;
//    node7->next = node8;
//    auto res2 = rotateRight(node6, 4);
//    display(res2);
//}
//
//int main()
//{
//    testRotateRight();
//
//    getchar();
//    return 0;
//}