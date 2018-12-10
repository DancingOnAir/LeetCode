#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> result(nums.size(), 1);
    if (nums.empty())
        return result;

    int fromBegin = 1, fromEnd = 1;
    int n = nums.size();
    for (auto i = 0; i < n; ++i)
    {
        result[i] *= fromBegin;
        fromBegin *= nums[i];

        result[n - 1 - i] *= fromEnd;
        fromEnd *= nums[n - 1 - i];
    }

    return result;
}

void testProductExceptSelf()
{
    vector<int> nums = { 1,2,3,4 };
    auto result = productExceptSelf(nums);

    for (auto& x : result)
        cout << x << ", ";
    cout << endl;
}

int main()
{
    testProductExceptSelf();
    getchar();
}