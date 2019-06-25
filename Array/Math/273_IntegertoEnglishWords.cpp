#include <iostream>
#include <string>

using namespace std;

string numberToWords(int num)
{
    if (num < 0)
        return "";

    string res("");
    return res;
}

void testNumberToWords()
{
    cout << numberToWords(123) << endl;
    cout << numberToWords(12345) << endl;
    cout << numberToWords(1234567) << endl;
    cout << numberToWords(12367891) << endl;
}

int main()
{
    testNumberToWords();

    getchar();
    return 0;
}