#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
//{
//	ListNode *p1 = l1;
//	ListNode *p2 = l2;
//	ListNode result(0);
//	ListNode *p = &result;
//
//	int v1 = 0;
//	int v2 = 0;
//	int i = 0, j = 0, k = 0, sum = 0;
//	int length = 0, x = 0;
//	while (p1 != nullptr)
//	{
//		v1 = v1 + p1->val * (int)pow(10, i);
//		p1 = p1->next;
//		++i;
//	}
//
//	while (p2 != nullptr)
//	{
//		v2 = v2 + p2->val * (int)pow(10, j);
//		p2 = p2->next;
//		++j;
//	}
//
//	sum = v1 + v2;
//	x = sum;
//	do
//	{
//		x = x / 10;
//		++length;
//	} while (x);
//
//	for (int l = 0; l < length; ++l)
//	{
//		p->next = new ListNode(sum % 10);
//		p = p->next;
//		sum = sum / 10;
//	}
//
//	return result.next;
//}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode preHead(0);
	ListNode *p = &preHead;
	int extra = 0;

	while (l1 || l2 || extra)
	{
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
		extra = sum / 10;

		p->next = new ListNode(sum%10);
		p = p->next;

		l1 = l1?l1->next:l1;
		l2 = l2?l2->next:l2;
	}

	return preHead.next;
}

int main()
{
	ListNode a(2), b(4), c(3), *head1, *p1;
	head1 = &a;
	a.next = &b;
	b.next = &c;
	c.next = nullptr;

	p1 = head1;

	//do
	//{
	//	cout << p1->val << ", ";
	//	p1 = p1->next;
	//} while (p1 != nullptr);
	//cout << endl;

	ListNode d(9), e(9), f(1), *head2, *p2;
	head2 = &d;
	d.next = &e;
	e.next = &f;
	f.next = nullptr;

	p2 = head2;
	//do
	//{
	//	cout << p2->val << ", ";
	//	p2 = p2->next;
	//} while (p2 != nullptr);
	//cout << endl;
	ListNode x(9);
	ListNode y(0);
	ListNode *p = addTwoNumbers(&x, p2);
	do
	{
		cout << p->val << ", ";
		p = p->next;
	} while (p != nullptr);
	cout << endl;

	system("pause");
	return 0;
}