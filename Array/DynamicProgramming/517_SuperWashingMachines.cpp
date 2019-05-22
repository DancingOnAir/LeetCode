#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinMoves(vector<int>& machines)
{
    if (machines.size() < 2)
        return 0;

    int res = 0;
    return res;
}

void testFindMinMoves()
{
    vector<int> machines = { 1,0,5 };
    cout << findMinMoves(machines) << endl;
}

int main()
{
    testFindMinMoves();

    getchar();
    return 0;
}