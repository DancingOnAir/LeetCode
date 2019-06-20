#include <iostream>
#include <string>

using namespace std;

int calculate(string s)
{

}

void testCalculate()
{
    cout << calculate("1 + 1") << endl;
    cout << calculate("2-1 + 2") << endl;
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
}

int main()
{
    testCalculate();

    getchar();
    return 0;
}