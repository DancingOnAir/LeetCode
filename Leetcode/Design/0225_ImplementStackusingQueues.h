#pragma once
#include <queue>

using namespace std;

class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {

    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1_.emplace(x);

        while (q1_.size() > 1)
        {
            q2_.emplace(q1_.front());
            q1_.pop();
        }
        
        while (!q2_.empty())
        {
            q1_.emplace(q2_.front());
            q2_.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int temp = q1_.front();
        q1_.pop();
        return temp;
    }

    /** Get the top element. */
    int top()
    {
        return q1_.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1_.size() == 0;
    }

private:
    queue<int> q1_;
    queue<int> q2_;
};
