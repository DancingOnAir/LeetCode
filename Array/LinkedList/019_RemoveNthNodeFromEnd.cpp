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