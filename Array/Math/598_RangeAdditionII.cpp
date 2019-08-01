#include <iostream>
#include <vector>

using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops)
{
    for (auto iter = ops.begin(); iter != ops.end(); ++iter)
    {
        m = m > (*iter)[0] ? (*iter)[0] : m;
        n = n > (*iter)[1] ? (*iter)[1] : n;
    }

    return m * n;
}

void testMaxCount()
{
    int m = 3, n = 3;
    vector<vector<int>> operations = { {2, 2},{3, 3} };
    cout << maxCount(m, n, operations) << endl;
}

int main()
{
    testMaxCount();

    getchar();
    return 0;
}