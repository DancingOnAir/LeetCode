#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    if (nums1.empty() || nums2.empty())
        return;

    copy(nums2.begin(), nums2.begin() + n, nums1.begin() + m);
    sort(nums1.begin(), nums1.begin() + m + n);
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0)
        nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
}

void testMerge()
{
    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    merge2(nums1, 3, nums2, 3);

    for (auto& x : nums1)
    {
        cout << x << ",";
    }

    cout << endl;
}

int main()
{
    testMerge();
    getchar();
}