#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int reverse(int x)
{
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoi(s);
}

void testReverse()
{
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(120) << endl;
}

int main()
{
    testReverse();
    getchar();
    return 0;
}