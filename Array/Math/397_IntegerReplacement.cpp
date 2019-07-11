#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> visited;
int integerReplacement(int n)
{
    if (n == 1)
        return 0;

    if (!visited.count(n))
    {
        if (n & 1)
            visited[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        else
            visited[n] = 1 + integerReplacement(n / 2);
    }

    return visited[n];
}

void testIntegerReplacement()
{
    cout << integerReplacement(8) << endl;
    cout << integerReplacement(7) << endl;
    cout << integerReplacement(65535) << endl;
}

int main()
{
    testIntegerReplacement();

    getchar();
    return 0;
}