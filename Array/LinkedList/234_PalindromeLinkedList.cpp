//#include <iostream>
//#include <string>
//
//struct ListNode
//{
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//ListNode* reverseList(ListNode *head)
//{
//    if (nullptr == head || nullptr == head->next)
//        return head;
//
//    ListNode *cur = head;
//    ListNode *pre = nullptr;
//    ListNode *next = nullptr;
//    while (cur != nullptr)
//    {
//        next = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = next;
//    }
//
//    return pre;
//}
//
//bool isPalindrome(ListNode* head)
//{
//    if (nullptr == head || nullptr == head->next)
//        return true;
//
//    ListNode *slow = head;
//    ListNode *fast = head;
//
//    while (fast->next != nullptr && fast->next->next != nullptr)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    slow->next = reverseList(slow->next);
//    slow = slow->next;
//    while (slow != nullptr)
//    {
//        if (head->val != slow->val)
//            return false;
//
//        slow = slow->next;
//        head = head->next;
//    }
//
//    return true;
//}
//
//
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
//ListNode *temp;
//
//bool check(ListNode *p)
//{
//    if (nullptr == p)
//        return true;
//
//    bool isPal = check(p->next) & (temp->val == p->val);
//    std::cout << (check(p->next) ? "T" : "F") << std::endl;
//    std::cout << (p->val == temp->val ? "T" : "F") << std::endl;
//    temp = temp->next;
//
//    return isPal;
//}
//
//bool isPalindrome1(ListNode *head)
//{
//    //ListNode *p = head;
//    temp = head;
//    return check(head);
//}
//
//void testIsPalindrome()
//{
//    ListNode *node1 = new ListNode(1);
//    ListNode *node2 = new ListNode(2);
//    ListNode *node3 = new ListNode(1);
//    ListNode *node4 = new ListNode(2);
//    ListNode *node5 = new ListNode(2);
//    ListNode *node6 = new ListNode(1);
//    node1->next = node2;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//
//    displayList(node1);
//    displayList(node3);
//    
//    std::cout << (isPalindrome1(node3) ? "T" : "F") << std::endl;
//}
//
//int main()
//{
//    testIsPalindrome();
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

ListNode* reverse(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
        return head;

    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* next = nullptr;

    while (cur)
    {
        next = cur->next;
        cur->next = pre;

        pre = cur;
        cur = next;
    }

    return pre;
}

bool isPalindrome(ListNode* head)
{
    if (!head || !head->next)
        return true;

    auto slow = head;
    auto fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;

    while (slow)
    {
        if (head->val != slow->val)
            return false;

        head = head->next;
        slow = slow->next;
    }

    return true;
}

void testIsPalindrome()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    cout << (isPalindrome(node1) ? "True" : "False") << endl;
}

int main()
{
    testIsPalindrome();

    getchar();
    return 0;
}