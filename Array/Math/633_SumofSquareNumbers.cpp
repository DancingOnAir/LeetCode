#include <iostream>
#include <unordered_set>

using namespace std;

bool judgeSquareSum(int c)
{
    if (c < 0)
        return false;

    unordered_set<int> s;
    for (long long i = 0; i * i <= c; ++i)
    {
        if (s.count(c - i * i) || c == 2 * i * i)
            return true;

        s.emplace(i * i);
    }

    return false;
}

void testJudgeSquareSum()
{
    cout << (judgeSquareSum(5) ? "True" : "False") << endl;
}

int main()
{
    testJudgeSquareSum();

    getchar();
    return 0;
}