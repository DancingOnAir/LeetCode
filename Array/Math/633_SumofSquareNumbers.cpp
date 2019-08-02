#include <iostream>
#include <unordered_set>

using namespace std;

bool judgeSquareSum2(int c)
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

bool judgeSquareSum(int c)
{
    long long top = sqrt(c);
    long long bottom = 0, sum = 0;
    while (bottom <= top)
    {
        sum = bottom * bottom + top * top;
        if (sum == c)
            return true;
        else if (sum < c)
            ++bottom;
        else
            --top;
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