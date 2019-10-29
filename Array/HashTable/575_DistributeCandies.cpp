#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
using namespace std;

int distributeCandies3(vector<int>& candies)
{
    if (candies.empty())
        return 0;

    unordered_map<int, int> count;
    int m = candies.size();

    for (int candy : candies)
    {
        ++count[candy];
    }

    return count.size() > m ? m : count.size();
}

int distributeCandies2(vector<int>& candies)
{
    return min(unordered_set<int>(candies.begin(), candies.end()).size(), candies.size() / 2);
}

int distributeCandies(vector<int>& candies)
{
    bitset<200001> hash;
    int count = 0;
    for (int i : candies)
    {
        if (!hash.test(i + 100000))
            ++count;
        hash.set(i + 100000);
    }

    int n = candies.size();
    return min(count, n / 2);
}

void testDistributeCandies()
{
    vector<int> candies = {1, 1, 2, 2, 3, 3};
    cout << distributeCandies(candies) << endl;
}

int main()
{
    testDistributeCandies();

    getchar();
    return 0;
}