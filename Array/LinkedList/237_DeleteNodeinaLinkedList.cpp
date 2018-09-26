//#include <iostream>
//
//struct ListNode
//{
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//void deleteNode(ListNode* node) 
//{
//    auto nextNode = node->next;
//    *node = *nextNode;
//
//    delete nextNode;
//}
//
//void displayList(ListNode *head)
//{
//    while (head)
//    {
//        std::cout << head->val << "->";
//        head = head->next;
//    }
//
//    std::cout << "NULL" <<  std::endl;
//}
//
//void testDeleteNode()
//{
//    ListNode *node1 = new ListNode(1);
//    ListNode *node2 = new ListNode(2);
//    ListNode *node3 = new ListNode(3);
//    ListNode *node4 = new ListNode(4);
//    ListNode *node5 = new ListNode(5);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    displayList(node1);
//    deleteNode(node2);
//    displayList(node1);
//}
//
//int main()
//{
//    testDeleteNode();
//    system("pause");
//    return 0;
//}