#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int findRotateSteps(string ring, string key)
{
    if (ring.empty() && !key.empty())
        return 0;

    int res = 0;
    return res;
}

void testFindRotateSteps()
{
    string ring = "godding", key = "gd";
    cout << findRotateSteps(ring, key) << endl;
}

int main()
{
    testFindRotateSteps();

    getchar();
    return 0;
}