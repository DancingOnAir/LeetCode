#pragma once
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isRectangleCover2(vector<vector<int>>& rectangles)
    {
        auto cmp = [&rectangles](const vector<int>& v1, const vector<int>& v2)
        {
            return v1[0] > v2[0] || v1[0] == v2[0] && v1[1] < v2[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < rectangles.size(); ++i)
        {
            // downY, in, idx
            q.push({ rectangles[i][1], 0, i });
            // upY, out, idx
            q.push({ rectangles[i][3], 1, i });
        }

        int l = INT_MAX;
        int r = INT_MIN;
        for (auto& rectangle : rectangles)
        {
            l = min(l, rectangle[0]);
            r = max(r, rectangle[2]);
        }
        q.push({ INT_MAX, 0 , 0 });

        int line = q.top()[0];
        map<int, int> curLine;
        int curWidth = 0;
        while (!q.empty())
        {
            auto v = q.top();
            q.pop();
            int left = rectangles[v[2]][0];
            int right = rectangles[v[2]][2];

            if (v[0] > line)
            {
                if (curWidth == 0)
                    return q.empty();
                if (curWidth != r - 1)
                    return false;
                if (curLine.begin()->first != l)
                    return false;
                auto last = curLine.end();
                last--;
                if (last->second != r)
                    return false;

                line = v[0];
            }

            if (v[1] == 0)
            {
                // p - (insert iter, bool: true for inserting, false for existing)
                auto p = curLine.insert({ left, right });
                if (!p.second)
                    return false;
                auto next = p.first;
                next++;
                if (next != curLine.end() && next->first < right)
                    return false;
                if (p.first != curLine.begin())
                {
                    auto prev = p.first;
                    prev--;
                    if (prev->second > left)
                        return false;
                }

                curWidth += right - left;

            }
            else
            {
                curLine.erase(left);
                curWidth -= right - left;
            }
        }

        return true;
    }

    bool isRectangleCover(vector<vector<int>>& rectangles)
    {
        map<int, vector<pair<int, int>>> insertInvertals;
        map<int, vector<pair<int, int>>> removeInvertals;

        for (int i = 0; i < rectangles.size(); ++i)
        {
            insertInvertals[rectangles[i][0]].emplace_back(make_pair(rectangles[i][1], rectangles[i][3]));
            removeInvertals[rectangles[i][2]].emplace_back(make_pair(rectangles[i][1], rectangles[i][3]));
        }

        auto iter1 = insertInvertals.begin();
        vector<pair<int, int>> temp;
        if (mergePairs(iter1->second, temp) == false || temp.size() > 1)
            return false;
        insertInvertals.erase(iter1);

        auto iter2 = removeInvertals.begin();
        while (iter2 != removeInvertals.end())
        {
            vector<pair<int, int>> remove;
            if (mergePairs(iter2->second, remove) == false)
                return false;
            if (insertInvertals.find(iter2->first) == insertInvertals.end())
            {
                if (removeInvertals.size() != 1)
                    return false;
            }
            else
            {
                vector<pair<int, int>> insert;
                if (mergePairs(insertInvertals[iter2->first], insert) == false)
                    return false;
                if (remove != insert)
                    return false;
                insertInvertals.erase(iter2->first);
            }

            removeInvertals.erase(iter2);
            iter2 = removeInvertals.begin();
        }
        
        return insertInvertals.empty();
    }

    bool mergePairs(vector<pair<int, int>>& pairs, vector<pair<int, int>>& temp)
    {
        sort(pairs.begin(), pairs.end(), 
            [&](const pair<int, int>& lhs, const pair<int, int>& rhs) { return lhs.first < rhs.first; });
        int curStart = pairs[0].first;

        for (int i = 1; i < pairs.size(); ++i)
        {
            if (pairs[i].first < pairs[i - 1].second)
                return false;

            if (pairs[i].first > pairs[i - 1].second)
            {
                temp.emplace_back(curStart, pairs[i - 1].second);
                curStart = pairs[i].first;
            }

        }
        temp.emplace_back(curStart, prev(pairs.end())->second);

        return true;
    }

    //struct ScanLine
    //{
    //    //int x_;
    //    //int upY_;
    //    //int downY_;
    //    //int isIn_;

    //    int left_;
    //    int right_;
    //    int height_;
    //    int isInLine_;
    //    ScanLine(int left, int right, int height, int isInLine) : x_(x), upY_(upY), downY_(downY), isIn_(isIn)
    //    {

    //    }
    //};

    //bool cmp(ScanLine& lhs, ScanLine& rhs)
    //{
    //    return lhs.x_ < rhs.x_;
    //}

};