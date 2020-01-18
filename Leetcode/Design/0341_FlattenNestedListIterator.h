#pragma once
#include <vector>
#include <stack>
using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        begins_.emplace(nestedList.begin());
        ends_.emplace(nestedList.end());
    }

    int next()
    {
        if (hasNext())
            return (begins_.top()++)->getInteger();
        return INT_MIN;
    }

    bool hasNext()
    {

        while (!begins_.empty())
        {
            if (begins_.top() == ends_.top())
            {
                begins_.pop();
                ends_.pop();
            }
            else
            {
                auto temp = begins_.top();
                if (temp->isInteger)
                    return true;

                begins_.top()++;
                begins_.emplace(temp->getList().begin());
                ends_.emplace(temp->getList().end());

            }
            
        }

        return false;
    }

private:
    stack<vector<NestedInteger>::iterator> begins_, ends_;
};