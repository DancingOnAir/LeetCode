#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isMax(vector<int>& nums, int pos)
{
    if (0 == pos)
        return true;

    int maxValue = INT_MIN;

    for (int i = pos; i >= 0; --i)
    {
        if (maxValue < nums[i])
        {
            maxValue = nums[i];
        }
    }

    return nums[pos] == maxValue;
}

int findMaxPosition(vector<int>& nums, int pos)
{
    if (0 == pos)
        return 0;

    int maxValue = INT_MIN;
    int res = 0;

    for (int i = 0; i < pos; ++i)
    {
        if (maxValue < nums[i])
        {
            maxValue = nums[i];
            res = i;
        }
    }

    return res;
}

int maximumSwap(int num)
{
    int res = 0;
    int length = 0;
    int maxPosition = 0;

    vector<int> digits;

    while (num != 0)
    {
        digits.emplace_back(num % 10);

        num /= 10;
        ++length;
    }
    
    for (int i = length - 1; i >= 0; --i)
    {
        if (isMax(digits, i))
            continue;

        maxPosition = findMaxPosition(digits, i);
        swap(digits[i], digits[maxPosition]);
        break;
    }

    for (int i = length - 1; i >= 0; --i)
    {
        res = res * 10 + digits[i];
    }

    return res;
}

int maximumSwap2(int num)
{
    string strNum = to_string(num);
    int maxId = INT_MIN, maxValue = INT_MIN;
    int leftId = INT_MIN, rightId = INT_MIN;

    for (int i = strNum.size() - 1; i >= 0; --i)
    {
        if (maxValue < strNum[i])
        {
            maxValue = strNum[i];
            maxId = i;
            continue;
        }

        if (strNum[i] < maxValue)
        {
            leftId = i;
            rightId = maxId;
        }
    }

    if (INT_MIN == leftId)
        return num;

    swap(strNum[leftId], strNum[rightId]);
    return stoi(strNum);
}

void testMaximumSwap()
{
    int num = 98368;
    int num2 = 1993;
    cout << maximumSwap2(num2) << endl;
}

int main()
{
    testMaximumSwap();
    getchar();
    return 0;
}