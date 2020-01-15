#pragma once
#include <vector>
using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool hasPeeked;
    int peekedElement;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.  
        hasPeeked = false;
        peekedElement = 0;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!hasPeeked)
        {
            peekedElement = Iterator::next();
            hasPeeked = true;
        }

        return peekedElement;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (!hasPeeked)
            return Iterator::next();

        int res = peekedElement;
        hasPeeked = false;
        peekedElement = 0;

        return res;
    }

    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }
};