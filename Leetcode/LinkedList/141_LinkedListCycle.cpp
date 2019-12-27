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
//bool hasCycle(ListNode *head)
//{
//    if (!head)
//        return false;
//
//    auto slow = head;
//    auto fast = head;
//
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//            return true;
//    }
//
//    return false;
//}
//
//void testHasCycle()
//{
//    ListNode* node1 = new ListNode(3);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node3 = new ListNode(0);
//    ListNode* node4 = new ListNode(-4);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node2;
//
//    cout << (hasCycle(node1) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testHasCycle();
//
//    getchar();
//    return 0;
//}