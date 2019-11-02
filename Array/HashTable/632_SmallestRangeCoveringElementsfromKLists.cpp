#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums)
{
    typedef vector<int>::iterator vi;
    struct comp
    {
        bool operator()(pair<vi, vi> p1, pair<vi, vi> p2)
        {
            return *p1.first > *p2.first;
        }
    };

    priority_queue<pair<vi, vi>, vector<pair<vi, vi>>, comp> pq;
    int lo = INT_MAX, hi = INT_MIN;
    for (auto& row : nums)
    {
        lo = min(lo, row[0]);
        hi = max(hi, row[0]);
        pq.push({ row.begin(), row.end() });
    }

    vector<int> res = { lo, hi };
    while (true)
    {
        auto p = pq.top();
        pq.pop();
        ++p.first;

        if (p.first == p.second)
            break;
        pq.push(p);

        lo = *pq.top().first;
        hi = max(hi, *p.first);
        if (hi - lo < res[1] - res[0])
            res = { lo, hi };
        }
   
    return res;
}

void display(const vector<int>& nums)
{
    if (nums.empty())
        return;

    for (int x : nums)
        cout << x << ", ";
    cout << endl;
}

void testSmallestRange()
{
    vector<vector<int>> nums1 = {{4, 10, 15, 24, 26}, 
                                {0, 9, 12, 20}, 
                                {5, 18, 22, 30}};

    auto res1 = smallestRange(nums1);
    display(res1);
}

int main()
{
    testSmallestRange();

    getchar();
    return 0;
}