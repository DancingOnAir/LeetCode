#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
    struct ScanLine
    {
        int x_;
        int downY_;
        int upY_;
        int isIn_;

        ScanLine(int x, int downY, int upY, int isIn) : x_(x), downY_(downY), upY_(upY), isIn_(isIn) {};
        bool operator<(const ScanLine& rhs) const
        {
            return x_ < rhs.x_;
        }
    };

    int rectangleArea(vector<vector<int>>& rectangles)
    {
        return 0;
    }
};