#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int leastInterval(vector<char>& tasks, int n)
{
    if (tasks.size() <= 1)
        return tasks.size();

    int count = 1;
    int maxValue = 0;
    int maxCount = 0;
    int res = 0;

    sort(tasks.begin(), tasks.end());

    for (int i = 1; i < tasks.size(); ++i)
    {
        if (tasks[i - 1] != tasks[i])
        {
            count = 1;
        }
        else
            ++count;

        if (count > maxValue)
        {
            maxValue = count;
            maxCount = 1;
        }
        else if (count == maxValue)
        {
            ++maxCount;
        }
    }

    res = maxValue + (maxCount - 1) + n * (maxValue - 1);
    return res > tasks.size()? res : tasks.size();
}

int leastInterval2(vector<char>& tasks, int n)
{
    unordered_map<char, int> m;
    int count = 0;

    for (char c : tasks)
    {
        m[c]++;
        count = max(count, m[c]);
    }

    int res = (count - 1) * (n + 1);
    for (auto& e : m)
        if (e.second == count)
            ++res;

    return max(res, (int)tasks.size());
}

void testLeastInterval()
{
    vector<char> tasks = { 'A','A','A','B','B','B' };
    vector<char> tasks2 = { 'A','B','A' };
    int n = 2;
    cout << leastInterval(tasks2, n) << endl;
}

int main()
{
    testLeastInterval();

    getchar();
    return 0;
}