////#include <iostream>
////#include <unordered_set>
////
////struct ListNode
////{
////    int val;
////    ListNode *next;
////    ListNode(int x) : val(x), next(nullptr) {}
////};
////
////ListNode *detectCycle(ListNode *head)
////{
////    if (nullptr == head || nullptr == head->next)
////        return nullptr;
////
////    ListNode *slow = head;
////    ListNode *fast = head;
////
////    while (fast->next != nullptr && fast->next->next != nullptr)
////    {
////
////
////        slow = slow->next;
////        fast = fast->next->next;
////
////        if (fast == slow)
////        {
////            fast = head;
////            while (fast != slow)
////            {
////                fast = fast->next;
////                slow = slow->next;
////            }
////
////            return fast;
////        }
////    }
////    return nullptr;
////}
////
////ListNode *detectCycle2(ListNode *head) 
////{
////    if (nullptr == head || nullptr == head->next)
////        return nullptr;
////
////    std::unordered_set<ListNode *> s;
////    while (head)
////    {
////        if (s.count(head))
////            return head;
////
////        s.insert(head);
////        head = head->next;
////    }
////
////    return nullptr;
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
////void testDetectCycle()
////{
////    ListNode *node1 = new ListNode(1);
////    ListNode *node2 = new ListNode(2);
////    ListNode *node3 = new ListNode(3);
////    ListNode *node4 = new ListNode(4);
////    ListNode *node5 = new ListNode(5);
////
////    node1->next = node2;
////    node2->next = node3;
////    node3->next = node4;
////    node4->next = node5;
////    node5->next = node3;
////    
////    //displayList(node1);
////    std::cout << detectCycle2(node1)->val << std::endl;
////
////}
////
////int main()
////{
////    testDetectCycle();
////    system("pause");
////    return 0;
////}
//
//
//#include <iostream>
//#include <unordered_set>
//using namespace std;
//
//struct ListNode
//{
//    int val;
//    ListNode* next;
//    ListNode(int x): val(x), next(nullptr) {}
//};
//
//ListNode *detectCycle2(ListNode *head)
//{
//    if (!head)
//        return nullptr;
//
//    auto slow = head, fast = head;
//    while (fast && fast->next != nullptr)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//
//        if (slow == fast)
//            break;
//    }
//
//    if (slow != fast)
//        return nullptr;
//
//    fast = head;
//    while (fast != slow)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//
//    return slow;
//}
//
//ListNode *detectCycle(ListNode *head)
//{
//    if (!head)
//        return nullptr;
//
//    auto cur = head;
//    unordered_set<ListNode*> s;
//    while (cur)
//    {
//        
//        if (s.count(cur))
//            return cur;
//        else
//            s.insert(cur);
//
//        cur = cur->next;
//    }
//
//    return nullptr;
//}
//
//void testDetectCycle()
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
//    auto res1 = detectCycle(node1);
//    cout << res1->val << endl;
//}
//
//int main()
//{
//    testDetectCycle();
//
//    getchar();
//    return 0;
//}