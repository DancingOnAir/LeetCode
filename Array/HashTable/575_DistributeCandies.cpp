#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int distributeCandies(vector<int>& candies)
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