//#include <iostream>
//#include <cstdlib>
//
//struct ListNode
//{
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//ListNode* deleteDuplicates(ListNode* head)
//{
//    if (nullptr == head || nullptr == head->next)
//        return head;
//
//    ListNode* p = head->next;
//    ListNode* pre = head;
//
//    while (p != nullptr)
//    {
//        if (pre->val == p->val)
//        {
//            while (p != nullptr && p->val == pre->val)
//            {
//                p = p->next;
//            }
//
//            pre->next = p;
//
//            if (nullptr == p)
//                return head;
//        }
//
//        p = p->next;
//        pre = pre->next;
//    }
//
//    return head;
//}
//
//void display(ListNode* head)
//{
//    if (nullptr == head)
//        return;
//
//    ListNode* p = head;
//
//    while (p != nullptr)
//    {
//        std::cout << p->val << "->";
//        p = p->next;
//    }
//
//    std::cout << "NULL" << std::endl;
//}
//
//int main()
//{
//    ListNode a(1), b(2), c(2), d(2), e(2);
//    ListNode* p;
//
//    a.next = &b;
//    b.next = &c;
//    c.next = &d;
//    d.next = &e;
//    p = &a;
//    
//    display(p);
//    display(deleteDuplicates(p));
//
//    system("pause");
//    return 0;
//}

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    if (!head || head->next == nullptr)
        return head;

    ListNode preHead = ListNode(0);
    preHead.next = head;

    ListNode* slow = &preHead;
    ListNode* fast = head;
    while (fast)
    {
        while (fast->next && fast->next->val == fast->val)
        {
            fast = fast->next;
        }

        slow->next = fast;
        slow = slow->next;
        fast = fast->next;
    }

    return preHead.next;
}

void display(ListNode* head)
{
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }

    cout << endl;
}

void testDeleteDupkicates()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    auto res1 = deleteDuplicates(node1);
    display(res1);
}

int main()
{
    testDeleteDupkicates();

    getchar();
    return 0;
}