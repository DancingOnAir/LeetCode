#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int countSegments(string s)
{
    istringstream iss(s);
    string str;
    //vector<string> res;
    int res = 0;
    while (iss >> str)
    {
        ++res;
    }

    return res;
}

void testCountSegments()
{
    string s1 = "Hello, my name is John";
    cout << countSegments(s1) << endl;
}

int main()
{
    testCountSegments();

    getchar();
    return 0;
}