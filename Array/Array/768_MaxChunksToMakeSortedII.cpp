#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int maxChunksToSorted(vector<int>& arr)
{
    if (arr.empty())
        return 0;

    vector<int> vec = arr;
    sort(vec.begin(), vec.end());
    int sum1 = 0, sum2 = 0, res = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        sum1 += arr[i];
        sum2 += vec[i];

        if (sum1 == sum2)
            ++res;
    }

    return res;
}

int maxChunksToSorted2(vector<int>& arr)
{
    vector<int> vec(arr.size());
    iota(vec.begin(), vec.end(), 0);
    sort(vec.begin(), vec.end(), [&arr](int i, int j) { return arr[i] == arr[j] ? i < j : arr[i] < arr[j]; });

    int res = 0;
    for (int i = 0, maxNum = 0; i < vec.size(); ++i)
    {
        maxNum = max(maxNum, vec[i]);
        if (maxNum == i)
            ++res;
    }

    return res;
}

void testMaxChunksToSorted()
{
    vector<int> arr1 = { 2,1,3,4,4 };
    vector<int> arr2 = { 5,4,3,2,1 };
    vector<int> arr3 = { 1,0,1,3,2 };

    cout << maxChunksToSorted2(arr1) << endl;
    cout << maxChunksToSorted2(arr2) << endl;
    cout << maxChunksToSorted2(arr3) << endl;
}

int main()
{
    testMaxChunksToSorted();
    getchar();
    return 0;
}