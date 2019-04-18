#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

bool canCross(vector<int>& stones)
{
    int n = stones.size();
    if (n < 1)
        return true;
    
    unordered_map<int, set<int>> m;
    m[0].emplace(1);
    for (int i = 0; i < n; ++i)
        m[stones[i]];

    for (int i = 0; i < n - 1; ++i)
    {
        for (int step : m[stones[i]])
        {
            int reach = step + stones[i];
            if (reach == stones[n - 1])
                return true;


            if (m.find(reach) != m.end())
            {
                if (step - 1 >= 0)
                    m[reach].emplace(step - 1);

                m[reach].emplace(step);
                m[reach].emplace(step + 1);
            }
        }
    }

    return false;
}

void testCanCross()
{
    vector<int> stones1{ 0,1,3,5,6,8,12,17 };
    vector<int> stones2{ 0,1,2,3,4,8,9,11 };
    cout << (canCross(stones1) ? "True" : "False") << endl;
    cout << (canCross(stones2) ? "True" : "False") << endl;
}

int main()
{
    testCanCross();

    getchar();
    return 0;
}