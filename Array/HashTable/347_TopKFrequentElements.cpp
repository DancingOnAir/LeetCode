#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int, int> m;
    for (int x : nums)
    {
        ++m[x];
    }

    map<int, vector<int>, greater<int>> n;
    for (auto iter : m)
    {
        n[iter.second].emplace_back(iter.first);
    }

    vector<int> res;
    for (auto iter = n.begin(); iter != n.end(); ++iter)
    {
        for (int x : iter->second)
        {
            if (res.size() >= k)
                return res;

            res.emplace_back(x);
        }
    }
    
    return res;
}

void displayResult(vector<int>&& nums)
{
    if (nums.empty())
        return;

    for (int x : nums)
        cout << x << ", ";
    cout << endl;
}

void testTopKFrequent()
{
    vector<int> nums1 = { 1, 1, 1, 2, 2, 3 };
    int k1 = 2;
    auto res1 = topKFrequent(nums1, k1);
    displayResult(move(res1));

    vector<int> nums2 = { 1 };
    int k2 = 1;
    auto res2 = topKFrequent(nums2, k2);
    displayResult(move(res2));
}

int main()
{
    testTopKFrequent();

    getchar();
    return 0;
}