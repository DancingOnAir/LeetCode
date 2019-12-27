//#include <iostream>
//#include <stack>
//using namespace std;
//
//struct ListNode
//{
//    int val;
//    ListNode* next;
//    ListNode(int x): val(x), next(nullptr) {}
//};
//
//ListNode* reverse(ListNode* head)
//{
//    if (!head || !head->next)
//        return head;
//
//    auto newHead = reverse(head->next);
//    head->next->next = head;
//    head->next = nullptr;
//
//    return newHead;
//}
//
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//    if (!l1)
//        return l2;
//
//    if (!l2)
//        return l1;
//
//    stack<int> s1, s2;
//    for (; l1; l1 = l1->next)
//        s1.emplace(l1->val);
//    for (; l2; l2 = l2->next)
//        s2.emplace(l2->val);
//
//    ListNode* res = new ListNode(0);
//    ListNode* tmp = nullptr;
//    for (int sum = 0; !s1.empty() || !s2.empty(); tmp = new ListNode(sum /= 10), tmp->next = res, res = tmp)
//    {
//        if (!s1.empty())
//            sum += s1.top(), s1.pop();
//
//        if (!s2.empty())
//            sum += s2.top(), s2.pop();
//
//        res->val = sum % 10;
//    }
//
//    return res->val ? res : res->next;
//}
//
//ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2)
//{
//    if (!l1)
//        return l2;
//
//    if (!l2)
//        return l1;
//
//    int v1 = 0, v2 = 0, val = 0, extra = 0;
//    auto newL1 = reverse(l1);
//    auto newL2 = reverse(l2);
//    ListNode preHead = ListNode(0);
//    auto p = &preHead;
//
//    while (newL1 || newL2 || extra)
//    {
//        v1 = newL1 ? newL1->val : 0;
//        v2 = newL2 ? newL2->val : 0;
//
//        val = (v1 + v2 + extra) % 10;
//        extra = (v1 + v2 + extra) / 10;
//
//        p->next = new ListNode(val);
//        p = p->next;
//
//        if (newL1)
//            newL1 = newL1->next;
//
//        if (newL2)
//            newL2 = newL2->next;
//    }
//
//    return reverse(preHead.next);
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
//void testAddTwoNumers()
//{
//    ListNode* l1 = new ListNode(7);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node3 = new ListNode(4);
//    ListNode* node4 = new ListNode(3);
//    l1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//
//    ListNode* l2 = new ListNode(5);
//    ListNode* node5 = new ListNode(6);
//    ListNode* node6 = new ListNode(4);
//    l2->next = node5;
//    node5->next = node6;
//
//    auto res1 = addTwoNumbers(l1, l2);
//    display(res1);
//}
//
//int main()
//{
//    testAddTwoNumers();
//
//    getchar();
//    return 0;
//}