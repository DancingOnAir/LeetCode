#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    ListNode preHead(INT_MIN);
    ListNode* p = &preHead;


    while (lists.size() > 1)
    {
        int minValue = INT_MAX;
        int pos = -1;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] == nullptr)
                continue;

            if (minValue > lists[i]->val)
            {
                minValue = lists[i]->val;
                pos = i;
            }
        }

        if (pos >= 0)
            lists[pos] = lists[pos]->next;

        for (auto iter = lists.begin(); iter != lists.end();)
        {
            if (*iter == nullptr)
                iter = lists.erase(iter);
            else
                ++iter;
        }


        if (minValue != INT_MAX)
        {
            p->next = new ListNode(minValue);
            p = p->next;
        }
    }

    if (!lists.empty())
        p->next = lists[0];

    return preHead.next;
}

void display(ListNode* head)
{
    if (!head)
    {
        cout << endl;
        return;
    }

    cout << head->val << "->";
    display(head->next);
}

void testMergeKLists()
{
    //vector<ListNode*> lists2 = { nullptr };
    //display(mergeKLists(lists2));

    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;

    ListNode *node4 = new ListNode(1);
    ListNode *node5 = new ListNode(3);
    ListNode *node6 = new ListNode(4);
    node4->next = node5;
    node5->next = node6;

    ListNode *node7 = new ListNode(2);
    ListNode *node8 = new ListNode(6);
    node7->next = node8;
    
    vector<ListNode*> lists1 = { node1, node4, node7 };
    display(mergeKLists(lists1));
}

int main()
{
    testMergeKLists();

    getchar();
    return 0;
}