//#include <iostream>
//#include <string>
//#include <vector>
//#include <sstream>
//using namespace std;
//
//
//// This is the interface that allows for creating nested lists.
//// You should not implement it, or speculate about its implementation
//class NestedInteger {
//  public:
//    // Constructor initializes an empty nested list.
//    NestedInteger();
//
//    // Constructor initializes a single integer.
//    NestedInteger(int value);
//
//    // Return true if this NestedInteger holds a single integer, rather than a nested list.
//    bool isInteger() const;
//
//    // Return the single integer that this NestedInteger holds, if it holds a single integer
//    // The result is undefined if this NestedInteger holds a nested list
//    int getInteger() const;
//
//    // Set this NestedInteger to hold a single integer.
//    void setInteger(int value);
//
//    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
//    void add(const NestedInteger &ni);
//
//    // Return the nested list that this NestedInteger holds, if it holds a nested list
//    // The result is undefined if this NestedInteger holds a single integer
//    const vector<NestedInteger> &getList() const;
//};
// 
//NestedInteger deserialize(istringstream& iss)
//{
//    int num;
//    if (iss >> num)
//        return NestedInteger(num);
//
//    iss.clear();
//    iss.get();
//
//    NestedInteger list;
//    while (iss.peek() != ']')
//    {
//        list.add(deserialize(iss));
//        if (iss.peek() == ',')
//            iss.get();
//    }
//
//    iss.get();
//    return list;
//}
//
//NestedInteger deserialize(string s)
//{
//    istringstream iss(s);
//
//    return deserialize(iss);
//}
//
//int main()
//{
//    getchar();
//    return 0;
//}