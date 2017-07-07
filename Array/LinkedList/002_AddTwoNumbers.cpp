#include <iostream>
#include <stdlib.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{

}

int main()
{
	ListNode l1(3);
	ListNode l2(4);
	ListNode l3(2);
	l3.next = &l2;
	l2.next = &l1;

	cout << "hello" << endl;
	system("pause");
	return 0;
}