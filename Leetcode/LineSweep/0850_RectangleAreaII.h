#pragma once
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{

private:
    const int mod = 1e9 + 7;
    int addArea(int prevArea, int w, int h)
    {
        return prevArea + ((long long)w * h) % mod;
    }

    vector<int> covers;
    vector<int> heights;
    vector<int> nodes;

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

    // segment tree method 1, line scan from left to right
    int rectangleArea1(vector<vector<int>>& rectangles)
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

    struct Segment
    {
        int start;
        int end;
        int height;
        bool in;

        Segment(): start(0), end(0), height(0), in(false){}

        Segment(int s, int e, int h, bool i) : start(s), end(e), height(h), in(i)
        {

        }
    };

    bool comp(const Segment& lhs, const Segment& rhs)
    {
        if (lhs.height == rhs.height)
            return lhs.start < rhs.start;
        return lhs.height < rhs.height;
    }

    vector<Segment> segs;
    map<pair<int, int>, int> cover;

    int coverRange()
    {
        if (cover.empty())
            return 0;

        int res = 0;
        auto iter = cover.begin();
        auto ptr = iter->first;
        int start = ptr.first;
        int end = ptr.second;

        ++iter;
        while (iter != cover.end())
        {
            ptr = iter->first;
            if (ptr.first > end)
            {
                res += (end - start);
                start = ptr.first;
                end = ptr.second;
            }
            else
            {
                end = max(end, ptr.second);
            }
            ++iter;
        }

        res += (end - start);
        return res;
    }
    //segment tree method 2
    int rectangleArea(vector<vector<int>>& rectangles)
    {
        if (rectangles.empty())
            return 0;

        for (const auto& rect : rectangles)
        {
            int x1 = rect[0];
            int x2 = rect[2];
            int y1 = rect[1];
            int y2 = rect[3];
            segs.emplace_back(Segment(x1, x2, y1, true));
            segs.emplace_back(Segment(x1, x2, y2, false));
        }

        sort(segs.begin(), segs.end(), comp);

        long long res = 0;
        int n = segs.size();
        int curHeight = segs[0].height;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i)
        {
            int cover = coverRange();
            res = (res + (segs[i].height - curHeight) * (long long)cover) % mod;

            curHeight = segs[i].height;
            auto 
        }

        return res;
    }

    int rectangleArea2(vector<vector<int>>& rectangles)
    {
        int OPEN = 0, CLOSE = 1;
        vector<vector<int>> events;
        int cnt = 0;
        for (auto& rectangle : rectangles)
        {
            events.push_back({ rectangle[1], OPEN, rectangle[0], rectangle[2] });
            events.push_back({ rectangle[3], CLOSE, rectangle[0], rectangle[2] });
        }

        sort(events.begin(), events.end(), [&](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0] < rhs[0]; });
        // save valid width of rectangles
        vector<vector<int>> active;
        int curY = events[0][0];
        long long res = 0;
        for (auto& e : events)
        {
            int y = e[0], type = e[1], x1 = e[2], x2 = e[3];
            long long query = 0;
            int cur = -1;
            
            for (auto& xs : active)
            {
                cur = max(cur, xs[0]);
                query += max(xs[1] - cur, 0);
                cur = max(cur, xs[1]);
            }

            res += query * (y - curY);

            if (type == OPEN)
            {
                active.push_back({ x1, x2 });
                sort(active.begin(), active.end(), [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0] < rhs[0]; });
            }
            else
            {
                for (auto iter = active.begin(); iter != active.end(); ++iter)
                {
                    if ((*iter)[0] == x1 && (*iter)[1] == x2)
                    {
                        active.erase(iter);
                        break;
                    }
                }
            }

            curY = y;
        }

        res %= 1000000007;
        return res;
    }

};
