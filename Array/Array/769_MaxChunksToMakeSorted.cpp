#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChunksToSorted(vector<int>& arr)
{
    int n = arr.size();
    if (n < 2)
        return n;

    int res = 0;
    for (int i = 0, maxNum = 0; i < n; ++i)
    {
        maxNum = max(maxNum, arr[i]);

        if (maxNum == i)
            ++res;
    }

    return res;
}

void testMaxChunksToSorted()
{
    vector<int> arr = { 1,0,2,3,4 };
    cout << maxChunksToSorted(arr) << endl;
}

int main()
{
    testMaxChunksToSorted();

    getchar();
    return 0;
}