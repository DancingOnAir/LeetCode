#include <iostream>
#include <stack>
#include <algorithm>
//class MinStack {
//public:
//    /** initialize your data structure here. */
//    MinStack()
//    {
//
//    }
//
//    void push(int x)
//    {
//        if (stk2.empty() || x <= getMin())
//            stk2.emplace(x);
//
//        stk1.emplace(x);
//    }
//
//    void pop()
//    {
//        if (stk1.top() == getMin())
//            stk2.pop();
//
//        stk1.pop();
//    }
//
//    int top()
//    {
//        return stk1.top();
//    }
//
//    int getMin()
//    {
//        return stk2.top();
//    }
//
//private:
//    std::stack<int> stk1;
//    std::stack<int> stk2;
//};

struct Node
{
    int min_;
    int val_;
    Node* next_;

    Node(int min, int val, Node* next = nullptr): min_(min), val_(val), next_(next) {}
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
    {
        head = new Node(INT_MAX, 0, nullptr);
    }

    void push(int x)
    {
        head = new Node(std::min(x, head->min_), x, head);
    }

    void pop()
    {
        auto toBeDelete = head;
        head = head->next_;
        delete toBeDelete;
    }

    int top()
    {
        return head->val_;
    }

    int getMin()
    {
        return head->min_;
    }

private:
    Node* head;
};

void test()
{
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    // Returns - 3.
    std::cout << minStack.getMin() << std::endl;
    minStack.pop();
    //Returns 0.
    std::cout << minStack.top() << std::endl;
    // Returns - 2.
    std::cout << minStack.getMin() << std::endl;
}

int main()
{
    test();

    getchar();
    return 0;
}