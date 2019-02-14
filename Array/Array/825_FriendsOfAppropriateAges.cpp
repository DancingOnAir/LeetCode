#include <iostream>
#include <vector>
#include <set>
using namespace std;

int numFriendRequests(vector<int>& ages)
{
    int res = 0;
    for (int i = 0; i < ages.size(); ++i)
    {
        for (int j = 0; j < ages.size(); ++j)
        {
            if (j == i || (ages[i] < 100 && ages[j] > 100))
                continue;

            if ((ages[j] > 0.5 * ages[i] + 7) && ages[i] >= ages[j])
                ++res;
        }
    }

    return res;
}

int numFriendRequests2(vector<int>& ages)
{
    int res = 0;
    vector<int> count(121, 0);
    for (int i = 0; i < ages.size(); ++i)
        count[ages[i]]++;

    for (int i = 0; i < ages.size(); ++i)
    {
        for (int j = 0.5 * ages[i] + 8; j <= ages[i]; ++j)
        {
            res += count[j];

            if (j == ages[i] && count[j])
                --res;
        }
    }


    return res;
}

void testNumFriendRequests()
{
    vector<int> ages = { 20,30,100,110,120 };
    vector<int> ages2 = { 16, 16 };
    cout << numFriendRequests2(ages2) << endl;
}

int main()
{
    testNumFriendRequests();

    getchar();
    return 0;
}