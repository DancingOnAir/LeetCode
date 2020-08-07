#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    auto dest = is_sorted_until(nums.rbegin(), nums.rend());

    if (dest != nums.rend()) {
        auto iter = upper_bound(nums.rbegin(), dest, *dest);
        swap(*iter, *dest);
    }

    reverse(nums.rbegin(), dest);
}

void nextPermutation1(vector<int>& nums) 
{
    bool bFlag = false;
    int size = nums.size();
    if (size == 0 || size == 1)
        return;

    int iMark = size - 1;
    int i, j;

    for (i = size - 1; i >= 0; --i)
    {
        if (nums[iMark] > nums[i])
        {
            for (j = size - 1; j > 0; --j)
            {
                if (nums[j] > nums[i])
                {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
                
            sort(nums.begin() + i + 1, nums.end());

            bFlag = true;
            break;
        }
        else
        {
            iMark = i;
        }
    }

    if (!bFlag)
        sort(nums.begin(), nums.end());
}

void display(const vector<int>& nums) {
    for (auto num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testNextPermutation() {
    // vector<int> nums1 { 5, 4, 7, 5, 3, 2 };
    // nextPermutation(nums1);
    // display(nums1);

    vector<int> nums2 { 10, 50, 60, 40, 30, 20 };
    nextPermutation(nums2);
    display(nums2);
}

int main(void) {
    testNextPermutation();

    return 0;
}