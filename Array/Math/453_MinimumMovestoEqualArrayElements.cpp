#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMoves(vector<int>& nums)
{
    size_t len = nums.size();
    if (len < 2)
        return 0;

    set<int> s;
    for (int x : nums)
        s.emplace(x);

    int res = 0;
    while (!s.empty())
    {
        auto iter = --(s.end());
        res += *iter - *s.begin();
        s.erase(iter);
    }

    return res;
}

void testMinMoves()
{
    vector<int> nums = { 1, 2, 3 };
    cout << minMoves(nums) << endl;
}

int main()
{
    testMinMoves();

    getchar();
    return 0;
}