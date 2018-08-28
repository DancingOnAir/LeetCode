#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n)
{
    vector<int> result(n + 1, 0);
    result[0] = 1;
    result[1] = 1;

    for (int i = 2; i < n + 1; ++i)
    {
        for (int j = 1; j <= i; ++j)
            result[i] += result[j - 1] * result[i - j];
    }
    
    return result[n];
}

int main(void)
{
    int n = 3;
    cout << numTrees(n) << endl;

    system("pause");
    return 0;
}