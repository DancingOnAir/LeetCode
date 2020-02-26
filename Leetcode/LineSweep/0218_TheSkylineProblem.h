#pragma once
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline1(vector<vector<int>>& buildings)
    {
        if (buildings.empty())
            return vector<vector<int>>();

        vector<vector<int>> res;
        multiset<pair<int, int>> all;
        for (auto& b : buildings)
        {
            all.emplace(make_pair(b[0], -b[2]));
            all.emplace(make_pair(b[1], b[2]));
        }

        multiset<int> heights{ 0 };
        vector<int> last{ 0, 0 };

        for (auto& p : all)
        {
            if (p.second < 0)
                heights.emplace(-p.second);
            else
                heights.erase(heights.find(p.second));

            int maxHeight = *heights.rbegin();

            if (last[1] != maxHeight)
            {
                last[0] = p.first;
                last[1] = maxHeight;

                res.emplace_back(last);
            }
        }

        return res;
    }

    struct Node
    {
        int x_;
        int h_;
        int isStart_;

        Node(int x, int h, int isStart) : x_(x), h_(h), isStart_(isStart)
        {

        }

        bool operator < (const Node& rhs)
        {
            //1. start node always prioritize end node
            //2. if both r start nodes, higher height first
            //3. if both r end nodes, lower height first
            if (x_ == rhs.x_)
                return h_ * isStart_ > rhs.h_ * rhs.isStart_;
            //4. lower x first
            return x_ < rhs.x_;
        }
    };

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        if (buildings.empty())
            return vector<vector<int>>();

        vector<vector<int>> res;
        vector<Node> nodes;

        for (const auto& b : buildings)
        {
            nodes.emplace_back(Node(b[0], b[2], 1));
            nodes.emplace_back(Node(b[1], b[2], -1));
        }

        sort(nodes.begin(), nodes.end());
        multiset<int, greater<int>> maxHeap{ 0 };
        int maxHeight = 0;

        for (auto node : nodes)
        {
            if (node.isStart_ == 1)
                maxHeap.emplace(node.h_);
            else
                maxHeap.erase(maxHeap.find(node.h_));

            if (*maxHeap.begin() != maxHeight)
            {
                res.push_back({ node.x_, *maxHeap.begin() });
                maxHeight = *maxHeap.begin();
            }
        }

        return res;
    }
};