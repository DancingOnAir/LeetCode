#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;
    Node() {}
    Node(int _val, Node* _next, Node* _random): val(_val), next(_next), random(_random) {}
};

Node* copyRandomList(Node* head)
{
    if (!head)
        return nullptr;

    unordered_map<Node*, Node*> m;
    Node* preHead = new Node(0, nullptr, nullptr);
    Node* first = preHead;

    for (auto cur = head; cur != nullptr; cur = cur->next)
    {
        Node* n = new Node(cur->val, nullptr, cur->random);
        preHead->next = n;
        preHead = preHead->next;

        m[cur] = n;
    }

    for (auto cur = first->next; cur != nullptr; cur = cur->next)
    {
        if (cur->random != nullptr)
            cur->random = m[cur->random];
    }

    auto res = first->next;
    delete first;

    return res;
}

void testCopyRandomList()
{
    Node* node1 = new Node(1, nullptr, nullptr);
    Node* node2 = new Node(2, nullptr, nullptr);
    node1->next = node2;
    node1->random = node2;
    node2->random = node2;

    auto res1 = copyRandomList(node1);
}

int main()
{
    testCopyRandomList();

    getchar();
    return 0;
}