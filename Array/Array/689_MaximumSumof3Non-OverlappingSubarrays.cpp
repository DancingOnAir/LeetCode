#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
{
    if (nums.empty() || k < 1 || k > nums.size() / 3)
        return {};

    int n = nums.size();
    int maxSum = 0;
    vector<int> sum = { 0 }, left(n, 0), right(n, n - k), res(3, 0);

    for (int i : nums)
        sum.emplace_back(sum.back() + i);

    for (int i = k, tot = sum[k] - sum[0]; i < n; ++i)
    {
        if (sum[i + 1] - sum[i + 1 - k] > tot)
        {
            left[i] = i + 1 - k;
            tot = sum[i + 1] - sum[i + 1 - k];
        }
        else
            left[i] = left[i - 1];
    }
    

    for (int i = n - k - 1, tot = sum[n] - sum[n - k]; i >= 0; --i)
    {
        if (sum[i + k] - sum[i] >= tot)
        {
            right[i] = i;
            tot = sum[i + k] - sum[i];
        }
        else
            right[i] = right[i + 1];
    }

    for (int i = k; i < n - 2 * k; ++i)
    {
        int l = left[i - 1], r = right[i + k];
        int tot = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
        if (tot > maxSum)
        {
            maxSum = tot;
            res = { l, i, r };
        }
    }

    return res;
}

void testMaxSumOfThreeSubarrays()
{
    vector<int> nums = { 1,2,1,2,6,7,5,1 };
    int k = 2;

    auto res = maxSumOfThreeSubarrays(nums, k);

    for (int x : res)
        cout << x << ", ";
    cout << endl;
}

int main()
{
    testMaxSumOfThreeSubarrays();
    getchar();
    return 0;
}