#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDistToClosest(vector<int>& seats)
{
    int n = seats.size();
    int maxDistance = 0;
    int pos = -1;
    int count = 0;
    int curDistance = 0;

    for (int i = 0; i < n; ++i)
    {
        if (seats[i] == 1)
        {
            pos = i;
            count = 0;
        }
        else
        {
            ++count;

            if (pos == -1)
            {
                curDistance = count;
            }
            else
            {
                curDistance = (count+1) / 2;
            }

            maxDistance = max(maxDistance, curDistance);
        }
    }

    return max(maxDistance, count);
}

void testMaxDistToClosest()
{
    vector<int> seats1 = { 1,0,0,0,1,0,1 };
    vector<int> seats2 = { 1,0,0,1 };
    cout << maxDistToClosest(seats2) << endl;
}

int main()
{
    testMaxDistToClosest();

    getchar();
    return 0;
}