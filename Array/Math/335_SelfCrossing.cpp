#include <iostream>
#include <vector>

using namespace std;

bool isSelfCrossing(vector<int>& x) {
    if ((x[0] < x[2]) || (x[1] > x[3]))
        return false;

    return true;
}

void testIsSelfCrossing()
{
    vector<int> x1{ 2, 1, 1, 2 };
    cout << (isSelfCrossing(x1) ? "True" : "False") << endl;

    vector<int> x2{ 1, 2, 3, 4 };
    cout << (isSelfCrossing(x2) ? "True" : "False") << endl;

    vector<int> x3{ 1, 1, 1, 1 };
    cout << (isSelfCrossing(x3) ? "True" : "False") << endl;
}

int main()
{
    testIsSelfCrossing();

    getchar();
    return 0;
}