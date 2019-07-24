#include <iostream>
#include <vector>

using namespace std;

int minMoves2(vector<int>& nums)
{
    int n = nums.size();
    if (n < 2)
        return 0;


}

void testMinMoves2()
{
    vector<int> nums = { 1, 2, 3 };
    cout << minMoves2(nums) << endl;
}

int main()
{
    testMinMoves2();

    getchar();
    return 0;
}