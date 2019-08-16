#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int compareVersion(string version1, string version2)
{
    vector<int> v1, v2;
    istringstream iss1(version1), iss2(version2);
    string temp;
    while (getline(iss1, temp, '.'))
    {
        v1.emplace_back(stoi(temp));
    }

    while (getline(iss2, temp, '.'))
    {
        v2.emplace_back(stoi(temp));
    }

    int n1 = v1.size();
    int n2 = v2.size();

    int i = 0;
    for (i = 0; i < n1 && i < n2; ++i)
    {
        if (v1[i] < v2[i])
            return -1;
        else if (v1[i] > v2[i])
            return 1;
    }

    if (n1 < n2)
    {
        for (int j = i; j < n2; ++j)
            if (v2[j] != 0)
                return -1;
    }
    else if (n1 > n2)
    {
        for (int j = i; j < n1; ++j)
            if (v1[j] != 0)
                return 1;
    }

    return 0;
}

void testCompareVersion()
{
    string version11 = "0.1", version21 = "1.1";
    cout << compareVersion(version11, version21) << endl;

    string version12 = "1.0.1", version22 = "1";
    cout << compareVersion(version12, version22) << endl;

    string version13 = "7.5.2.4", version23 = "7.5.3";
    cout << compareVersion(version13, version23) << endl;

    string version14 = "1.01", version24 = "1.001";
    cout << compareVersion(version14, version24) << endl;

    string version15 = "1.0", version25 = "1.0.0";
    cout << compareVersion(version15, version25) << endl;
}

int main()
{
    testCompareVersion();

    getchar();
    return 0;
}