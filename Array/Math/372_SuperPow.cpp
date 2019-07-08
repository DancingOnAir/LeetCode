#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int superPow(int a, vector<int>& b)
{
    if (b.empty())
        return 0;
    
    int num = 0;
    for (int i = 0; i < b.size(); ++i)
    {
        num = num * 10 + b[i];
    }

    int res = log()
}

void testSuperPow()
{
    vector<int> b1 = { 3 };
    cout << superPow(2, b1) << endl;

    vector<int> b2 = { 1, 0 };
    cout << superPow(2, b2) << endl;
}

int main()
{
    getchar();
    return 0;
}