#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Greedy
bool canJump(vector<int>& nums)
{
    if (nums.empty())
        return true;

    int farest = 0, n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (farest < i)
            return false;

        farest = max(farest, i + nums[i]);
    }

    return true;
}


//DP
bool canJump2(vector<int>& nums)
{
    if (nums.empty())
        return true;

    int n = nums.size();
    vector<bool> jump(n, false);
    jump[n - 1] = true;
    
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j <= nums[i]; ++j)
        {
            if (true == jump[i + j])
            {
                jump[i] = true;
                break;
            }
        }
    }

    return jump[0];
}

void testCanJump()
{
    vector<int> input = { 2, 3, 1, 1, 4 };

    //vector<int> input = { 3, 2, 1, 0, 4 };
    bool result = canJump2(input);
    cout << (result ? "true" : "false") << endl;
}

int main()
{
    testCanJump();
    system("pause");
    return 0;
}