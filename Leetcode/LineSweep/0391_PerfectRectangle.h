#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>>& rectangles)
    {
        return true;
    }

    struct ScanLine
    {
        int x_;
        int upY_;
        int downY_;

        int isIn_;
        ScanLine(int x, int upY, int downY, int isIn) : x_(x), upY_(upY), downY_(downY), isIn_(isIn)
        {

        }
    };

    bool cmp(ScanLine& lhs, ScanLine& rhs)
    {
        return lhs.x_ < rhs.x_;
    }

};