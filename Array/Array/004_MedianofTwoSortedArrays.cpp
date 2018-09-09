#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	double median = 0;

	nums1.insert(nums1.end(), nums2.begin(), nums2.end());
	
	int size = nums1.size();
	if (size % 2 != 0)
	{	

		nth_element(nums1.begin(), nums1.begin() + size / 2, nums1.end());
		median = nums1.at(size / 2);
	}
	else
	{
		nth_element(nums1.begin(), nums1.begin() + size / 2 - 1, nums1.end());
		median = nums1.at(size / 2 - 1);
		nth_element(nums1.begin(), nums1.begin() + size / 2, nums1.end());
		median = (median + nums1.at(size / 2))/2;
	}

	return median;
}

double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();
    int m = nums2.size();

    if (n > m)
        return findMedianSortedArrays2(nums2, nums1);

    int L1, L2, R1, R2, c1, c2, lo = 0, hi = 2*n;

    while (lo <= hi)
    {
        c1 = (lo + hi) / 2;
        c2 = m + n - c1;

        L1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
        R1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
        L2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
        R2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

        if (L1 > R2)
            hi = c1 - 1;
        else if (L2 > R1)
            lo = c1 + 1;
        else
            break;
    }

    return (max(L1, L2) + min(R1, R2)) / 2.0;
}

int main(void)
{
	int a[] = { 1, 2 };
	int b[] = { 3, 4};
	vector<int> nums1(a, a + 2);
	vector<int> nums2(b, b + 2);

	cout << findMedianSortedArrays2(nums1, nums2) << endl;

	system("pause");

	return 0;
}