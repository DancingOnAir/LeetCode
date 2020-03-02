#pragma once
#include <vector>
#include <set>
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

    void pushup(int start, int end, int segIndex)
    {
        if (covers[segIndex])
            heights[segIndex] = nodes[end] - nodes[start];
        else if (start + 1 == end)
            heights[segIndex] = 0;
        else
            heights[segIndex] = heights[segIndex << 1] + heights[segIndex << 1 | 1];
    }

    void updateSegmentTree(int downYIndex, int upYIndex, int isIn, int start, int end, int segIndex)
    {
        if (downYIndex > end || upYIndex < start)
            return;

        if (downYIndex <= start && upYIndex >= end)
        {
            covers[segIndex] += isIn;
            pushup(start, end, segIndex);
            return;
        }

        if (start + 1 == end)
            return;

        int mid = start + ((end - start) >> 1);
        if (downYIndex <= mid)
            updateSegmentTree(downYIndex, upYIndex, isIn, start, mid, segIndex << 1);
        if (upYIndex > mid)
            updateSegmentTree(downYIndex, upYIndex, isIn, mid, end, segIndex << 1 | 1);

        pushup(start, end, segIndex);
    }

    int rectangleArea(vector<vector<int>>& rectangles)
    {
        vector<ScanLine> lines;
        nodes.emplace_back(0);

        lines.emplace_back(ScanLine(0, 0, 0, 0));

        for (int i = 0; i < rectangles.size(); ++i)
        {
            lines.emplace_back(ScanLine(rectangles[i][0], rectangles[i][1], rectangles[i][3], 1));
            lines.emplace_back(ScanLine(rectangles[i][2], rectangles[i][1], rectangles[i][3], -1));
            nodes.emplace_back(rectangles[i][1]);
            nodes.emplace_back(rectangles[i][3]);
        }

        sort(lines.begin(), lines.end());
        sort(nodes.begin(), nodes.end());
        unique(next(nodes.begin()), nodes.end());
        
        int res = 0;
        heights.resize(nodes.size() * 2, 0);
        covers.resize(nodes.size() * 2, 0);

        for (int i = 1; i < lines.size(); ++i)
        {
            res =  (res + heights[1] * ((long long)lines[i].x_ - lines[i - 1].x_)) % 1000000007;
            int left = lower_bound(next(nodes.begin()), nodes.end(), lines[i].downY_) - nodes.begin();
            int right = lower_bound(next(nodes.begin()), nodes.end(), lines[i].upY_) - nodes.begin();

            updateSegmentTree(left, right, lines[i].isIn_, 1, nodes.size() - 1, 1);
        }

        return res;
    }
private:
    vector<int> covers;
    vector<int> heights;
    vector<int> nodes;
};
