#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node () {}
    Node(int _val, Node* _prev, Node* _next, Node* _child): val(_val), prev(_prev), next(_next), child(_child) {}
};

Node* flatten(Node* head)
{
    if (!head)
        return nullptr;

    auto cur = head;
    while (cur)
    {
        while (cur && !cur->child)
        {
            cur = cur->next;
        }

        if (!cur)
            return head;

        auto next = cur->next;
        auto newHead = flatten(cur->child);
        cur->next = newHead;
        cur->child = nullptr;
        newHead->prev = cur;

        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = next;

        if (next)
            next->prev = cur;
    }

    return head;
}

void display(Node* head)
{
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }

    cout << "null" << endl;
}

void testFlatten()
{
    Node* node1 = new Node(1, nullptr, nullptr, nullptr);
    Node* node2 = new Node(2, nullptr, nullptr, nullptr);
    Node* node3 = new Node(3, nullptr, nullptr, nullptr);
    Node* node4 = new Node(4, nullptr, nullptr, nullptr);
    Node* node5 = new Node(5, nullptr, nullptr, nullptr);
    Node* node6 = new Node(6, nullptr, nullptr, nullptr);
    Node* node7 = new Node(7, nullptr, nullptr, nullptr);
    Node* node8 = new Node(8, nullptr, nullptr, nullptr);
    Node* node9 = new Node(9, nullptr, nullptr, nullptr);
    Node* node10 = new Node(10, nullptr, nullptr, nullptr);
    Node* node11 = new Node(11, nullptr, nullptr, nullptr);
    Node* node12 = new Node(12, nullptr, nullptr, nullptr);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node2->prev = node1;
    node3->prev = node2;
    node4->prev = node3;
    node5->prev = node4;
    node6->prev = node5;

    node3->child = node7;

    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node8->prev = node7;
    node9->prev = node8;
    node10->prev = node9;

    node8->child = node11;

    node11->next = node12;
    node12->prev = node11;

    auto res1 = flatten(node1);
    display(res1);
}

int main()
{
    testFlatten();

    getchar();
    return 0;
}