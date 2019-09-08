#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n)
{
    vector<int> res(n + 1);
    res[0] = res[1] = 1;

    for (int i = 2; i < n + 1; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            res[i] += res[j] * res[i - j - 1];
        }
    }

    return res[n];
}

void testNumTrees()
{
    int n = 3;
    cout << numTrees(n) << endl;
}

int main(void)
{
    testNumTrees();

    getchar();
    return 0;
}