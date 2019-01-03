#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int>& nums)
{
    int res = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        if (i % 2 == 0)
            res += nums[i];
    }

    return res;
}

int arrayPairSum2(vector<int>& nums)
{
    vector<int> hashTable(20001, 0);

    for (int i = 0; i < nums.size(); ++i)
    {
        hashTable[nums[i] + 10000]++;
    }

    int res = 0;
    int flag = 0;

    for (int i = 0; i < 20001;)
    {
        if (hashTable[i] > 0 && 0 == flag)
        {
            flag = 1;
            res += i - 10000;
            hashTable[i]--;
        }
        else if (hashTable[i] > 0 && 1 == flag)
        {
            flag = 0;
            hashTable[i]--;
        }
        else
            ++i;
    }

    return res;
}

void testArrayPairSum()
{
    vector<int> nums = { 1,4,3,2 };
    cout << arrayPairSum2(nums) << endl;
}

int main()
{
    testArrayPairSum();

    getchar();
    return 0;
}