#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMaxAverage(vector<int>& nums, int k)
{
    int n = nums.size();
    if (n < k)
        return 0;

    double sum = 0, res = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i < k)
            sum += nums[i];

        else
        {
            res = max(sum, res);
            sum += nums[i] - nums[i - k];
        }
    }

    res = max(sum, res);
    return res / k;
}



void testFindMaxAverage()
{
    vector<int> nums = { 1,12,-5,-6,50,3 };
    int k = 4;

    cout << findMaxAverage(nums, k) << endl;
}

int main()
{
    testFindMaxAverage();

    getchar();
    return 0;
}