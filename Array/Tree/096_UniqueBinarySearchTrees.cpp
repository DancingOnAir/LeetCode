#include <iostream>
#include <vector>

using namespace std;

//int numTrees(int n)
//{
//    vector<int> result(n + 1, 0);
//    result[0] = 1;
//    result[1] = 1;
//
//    for (int i = 2; i < n + 1; ++i)
//    {
//        for (int j = 1; j <= i; ++j)
//            result[i] += result[j - 1] * result[i - j];
//    }
//    
//    return result[n];
//}

int numTrees(int n)
{
    vector<int> res(n + 1);
    res[0] = res[1] = 1;

    for (int i = 2; i < n + 1; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            res[i] += res[j - 1] * res[i - j];
        }
    }
}

void testNumTrees()
{
    int n = 3;
    cout << numTrees(n) << endl;
}

int main(void)
{
    getchar();
    return 0;
}