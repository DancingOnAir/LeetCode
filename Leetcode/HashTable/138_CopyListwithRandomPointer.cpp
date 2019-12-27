//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <queue>
//using namespace std;
//
//struct Node
//{
//    int val;
//    Node* next;
//    Node* random;
//    Node() {};
//    Node(int _val, Node* _next, Node* _random) : val(_val), next(_next), random(_random)
//    {
//
//    }
//};
//
//unordered_map<int, Node*> m;
//
//Node* copyRandomList(Node* head)
//{
//    if (!head)
//        return nullptr;
//
//    if (m.count(head->val))
//        return m[head->val];
//
//    Node* node = new Node(head->val, nullptr, nullptr);
//    m[node->val] = node;
//    node->next = copyRandomList(head->next);
//    node->random = copyRandomList(head->random);
//
//    return node;
//}
//
//void testCopyRandomList()
//{
//    Node* node2 = new Node(2, nullptr, nullptr);
//    Node* node1 = new Node(1, nullptr, node2);
//    auto res = copyRandomList(node1);
//}
//
//int main()
//{
//    testCopyRandomList();
//
//    getchar();
//    return 0;
//}