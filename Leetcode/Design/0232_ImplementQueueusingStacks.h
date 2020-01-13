#pragma once
#include <stack>

using namespace std;

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {

    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        input.emplace(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int temp = peek();
        output.pop();

        return temp;
    }

    /** Get the front element. */
    int peek()
    {
        if (output.empty())
        {
            while (input.size())
            {
                output.emplace(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return input.empty() && output.empty();
    }

private:
    stack<int> input;
    stack<int> output;
};