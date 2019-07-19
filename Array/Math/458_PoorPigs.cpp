#include <iostream>
#include <cmath>
using namespace std;

int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
    if (buckets < 2 || minutesToDie < 0 || minutesToTest < 1 || minutesToTest / minutesToDie < 1)
        return 0;

    int res = 0;
    while (pow((minutesToTest / minutesToDie + 1), res) < buckets)
        ++res;

    return res;
}

void testPoorPigs()
{
    cout << poorPigs(1000, 15, 60) << endl;
}

int main()
{
    testPoorPigs();

    getchar();
    return 0;
}