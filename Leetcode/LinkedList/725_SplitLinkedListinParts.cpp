//#include <iostream>
//#include <vector>
//#include <math.h>
//using namespace std;
//
//struct ListNode
//{
//    int val;
//    ListNode* next;
//    ListNode(int x): val(x), next(nullptr) {}
//};
//
//vector<ListNode*> splitListToParts(ListNode* root, int k)
//{
//    if (1 == k)
//        return vector<ListNode*> {root};
//
//    int len = 0;
//    ListNode* cur = root;
//    while (cur)
//    {
//        ++len;
//        cur = cur->next;
//    }
//
//    int n = len / k;
//    int r = len % k;
//    cur = root;
//
//    vector<ListNode*> res(k, nullptr);
//    ListNode* next = nullptr;
//    for (int i = 0; i < k && cur; ++i)
//    {
//        res[i] = cur;
//        for (int j = 1; j < n + (i < r ? 1: 0); ++j)
//        {
//            cur = cur->next;
//        }
//
//        next = cur->next;
//        cur->next = nullptr;
//        cur = next;
//    }
//
//    return res;
//}
//
//void display(const vector<ListNode*>& vec)
//{
//    for (auto v : vec)
//    {
//        while (v)
//        {
//            cout << v->val << "->";
//            v = v->next;
//        }
//        cout << "null" << endl;
//    }
//}
//
//void testSplitListToParts()
//{
//    ListNode* root1 = new ListNode(1);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node3 = new ListNode(3);
//    ListNode* node4 = new ListNode(4);
//    ListNode* node5 = new ListNode(5);
//    ListNode* node6 = new ListNode(6);
//    ListNode* node7 = new ListNode(7);
//
//    root1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
//
//    auto res1 = splitListToParts(root1, 5);
//    display(res1);
//
//    ListNode* root2 = new ListNode(1);
//    ListNode* node8 = new ListNode(2);
//    ListNode* node9 = new ListNode(3);
//    root2->next = node8;
//    node8->next = node9;
//
//    auto res2 = splitListToParts(root2, 5);
//    display(res2);
//}
//
//int main()
//{
//    testSplitListToParts();
//    getchar();
//    return 0;
//}