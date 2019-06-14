#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string s) 
{
    if (s.empty())
        return 0;

    int res = 0;
    return res;
}

void testTitleToNumber()
{
    cout << titleToNumber("A") << endl;
    cout << titleToNumber("Z") << endl;
    cout << titleToNumber("AB") << endl;
    cout << titleToNumber("ZY") << endl;
}

int main()
{
    testTitleToNumber();

    getchar();
    return 0;
}