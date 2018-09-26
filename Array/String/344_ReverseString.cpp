#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseString(string s)
{
    if (s.empty())
        return s;

    size_t len = s.size();
    for (size_t i = 0; i < len / 2; ++i)
    {
        swap(s[i], s[len - 1 - i]);
    }

    return s;
}

void testReverseString()
{
    string s = "hello";
    cout << s << endl;
    string result = reverseString(s);
    cout << result << endl;
}

int main()
{
    testReverseString();
    system("pause");
    return 0;
}