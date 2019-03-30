#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j)
{
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j])
    {
        ++i;
        ++j;
    }

    return (j == nums2.size()) || (i < nums1.size() && nums1[i] > nums2[j]);
}

vector<int> merge(vector<int>&& nums1, vector<int>&& nums2)
{
    int k = nums1.size() + nums2.size();
    vector<int> res(k);

    for (int r = 0, i = 0, j = 0; r < k; ++r)
    {
        res[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
    }

    return res;
}

vector<int> maxArray(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> res(k);

    for (int i = 0, j = 0; i < n; ++i)
    {
        while (n - i + j > k && j > 0 && res[j - 1] < nums[i])
            --j;

        if (j < k)
            res[j++] = nums[i];
    }

    return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
    int l1 = nums1.size();
    int l2 = nums2.size();

    vector<int> res(k);
    for (int i = max(0, k - l2); i <= k && i <= l1; ++i)
    {
        vector<int> candidate = move(merge(maxArray(nums1, i), maxArray(nums2, k - i)));
        if (greater(candidate, 0, res, 0))
            res = move(candidate);
    }

    return res;
}

void testMaxNumber()
{
    vector<int> nums1 = { 3, 4, 6, 5 };
    vector<int> nums2 = { 9, 1, 2, 5, 8, 3 };
    int k = 5; 

    auto res = maxNumber(nums1, nums2, k);
    for (int x : res)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    testMaxNumber();

    getchar();
    return 0;
}