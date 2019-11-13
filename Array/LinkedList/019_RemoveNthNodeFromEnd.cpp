//#include <iostream>
//#include <stdlib.h>
//
//using namespace std;
//
//struct ListNode
//{
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(nullptr) {}
//};
//
//ListNode* removeNthFromEnd(ListNode* head, int n) 
//{
//	//ListNode *p = head;
//	//ListNode *q = head;
//	//int length = 0;
//	//while (p != nullptr)
//	//{
//	//	p = p->next;
//	//	++length;
//	//}
//
//	//if (n > length)
//	//	return head;
//
//	//for (int i = 0; i < length - n - 1; ++i)
//	//{
//	//	q = q->next;
//	//}
//
//	//ListNode *tempNode = q->next;
//	//q->next = tempNode->next;
//
//	//return head;
//
//	ListNode preHead(0);
//	ListNode *p = head;
//	ListNode *q = &preHead;
//	preHead.next = head;
//
//	for (int i = 1; i < n; ++i)
//	{
//		p = p->next;
//	}
//
//	for (int i = 1; p->next != nullptr; ++i)
//	{
//		q = q->next;
//		p = p->next;
//	}
//
//	ListNode *toBeDelete = q->next;
//	q->next = q->next->next;
//	delete toBeDelete;
//
//	return preHead.next;
//}
//
//int main()
//{
//	ListNode a(1), b(2), c(3), d(4), e(5);
//	ListNode *p;
//	p = &a;
//	//a.next = &b;
//	//b.next = &c;
//	//c.next = &d;
//	//d.next = &e;
//	
//	ListNode *result = removeNthFromEnd(p, 1);
//
//	do
//	{
//		cout << result->val << ", ";
//		result = result->next;
//	} while (result != nullptr);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd2(ListNode* head, int n) 
{

    ListNode* preHead = new ListNode(0);
    preHead->next = head;

    ListNode* fast = preHead;
    ListNode* slow = preHead;
    for (int i = n; i >= 0; --i)
    {
        if (!fast)
            return nullptr;

        fast = fast->next;
    }

    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return preHead->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode preHead(0);
    preHead.next = head;

    ListNode* p = &preHead;
    ListNode* q = &preHead;
    for (int i = 0; i < n; ++i)
        p = p->next;

    for (int i = 0; p->next != nullptr; ++i)
    {
        p = p->next;
        q = q->next;
    }

    ListNode* toBeDelete = q->next;
    q->next = toBeDelete->next;
    delete toBeDelete;

    return preHead.next;
}

void display(ListNode* node)
{
    if (!node)
    {
        cout << endl;
        return;
    }

    cout << node->val << "->";
    display(node->next);
}

void testRemoveNthFromEnd()
{
    ListNode* node6 = new ListNode(1);
    ListNode* node7 = new ListNode(2);
    node6->next = node7;
    auto res2 = removeNthFromEnd(node6, 2);
    display(res2);

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    auto res1 = removeNthFromEnd(node1, 2);
    display(res1);
}

int main()
{
    testRemoveNthFromEnd();

    getchar();
    return 0;
}