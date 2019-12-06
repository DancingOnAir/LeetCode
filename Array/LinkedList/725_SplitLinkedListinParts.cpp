#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

vector<ListNode*> splitListToParts(ListNode* root, int k)
{
    if (1 == k)
        return vector<ListNode*> {root};

    vector<ListNode*> res;
    int s = 0;
    auto p = root;
    while (p)
    {
        ++s;
        p = p->next;
    }

    int a = s / k;
    int b = s % k;

    ListNode* newHead = nullptr;
    ListNode* next = nullptr;

    while (root)
    {

        newHead = root;
        
        int flag = b > 0 ? 1 : 0;
        for (int i = 0; i < a + flag - 1; ++i)
        {
            root = root->next;
        }

        next = root->next;
        root->next = nullptr;
        root = next;

        --b;
        --k;
        res.emplace_back(newHead);
    }

    while (k--)
    {
        res.emplace_back(nullptr);
    }

    return res;
}

void display(const vector<ListNode*>& vec)
{
    for (auto v : vec)
    {
        while (v)
        {
            cout << v->val << "->";
            v = v->next;
        }
        cout << "null" << endl;
    }
}

void testSplitListToParts()
{
    ListNode* root1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);

    root1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    auto res1 = splitListToParts(root1, 5);
    display(res1);

    ListNode* root2 = new ListNode(1);
    ListNode* node8 = new ListNode(2);
    ListNode* node9 = new ListNode(3);
    root2->next = node8;
    node8->next = node9;

    auto res2 = splitListToParts(root2, 5);
    display(res2);
}

int main()
{
    testSplitListToParts();
    getchar();
    return 0;
}