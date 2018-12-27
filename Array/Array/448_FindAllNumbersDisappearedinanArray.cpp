#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i)
    {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > 0)
            res.emplace_back(i + 1);
    }

    return res;
}

void testFindDisappearedNumbers()
{
    vector<int> nums = { 4,3,2,7,8,2,3,1 };
    auto res = findDisappearedNumbers(nums);
    for (auto x : res)
        cout << x << ", ";
    cout << endl;
}

int main()
{
    testFindDisappearedNumbers();

    getchar();
    return 0;
}