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
        int l, r, z, cover;
        Node* left;
        Node* right;
        Node() : left(nullptr), right(nullptr), z(0), cover(0)
        {

        }

        void buildTree(int x, int y)
        {
            l = x;
            r = y;
            if (x < y)
            {
                int mid = x + y >> 1;
                left = new Node();
                left->buildTree(x, mid);
                right = new Node();
                right->buildTree(mid + 1, y);
            }
        }

        void change(int x, int y, int c)
        {
            if (l == x && r == y)
            {
                cover += c;
                if (cover == 0)
                    z = left != nullptr ? left->z + right->z : 0;

                if (cover == 1)
                    z = r - l + 1;
            }
        }
    };

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        if (buildings.empty())
            return vector<vector<int>>();

        vector<vector<int>> res;
        return res;
    }
};