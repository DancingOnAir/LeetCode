#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string smallestGoodBase(string n)
{
    if (n.empty())
        return "";
}

void testSmallestGoodBase()
{
    cout << smallestGoodBase("13") << endl;
    cout << smallestGoodBase("4681") << endl;
    cout << smallestGoodBase("1000000000000000000") << endl;
}

int main()
{
    testSmallestGoodBase();

    getchar();
    return 0;
}