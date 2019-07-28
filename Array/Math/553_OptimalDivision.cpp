#include <iostream>
#include <string>
#include <vector>

using namespace std;

string optimalDivision(vector<int>& nums)
{
    int n = nums.size();
    if (0 == n)
        return "";

    if (1 == n)
        return to_string(nums[0]);
}

void testOptimalDivision()
{
    vector<int> nums{ 1000,100,10,2 };
    cout << optimalDivision(nums) << endl;
}

int main()
{
    testOptimalDivision();

    getchar();
    return 0;
}