#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void getSpecificNumber(map<char, int>& m, map<int, int>& res, vector<string>& nums, int idx, char c)
{
    if (m.count(c) && m[c] > 0)
    {
        res[idx] = m[c];

        for (char x : nums[idx])
            m[x] -= res[idx];
    }
}

string originalDigits(string s)
{
    vector<string> nums= { "zero", "one", "two", "three", "four", 
        "five", "six", "seven", "eight", "nine" };

    map<char, int> m;
    for (char c : s)
        m[c]++;

    map<int, int> res;
    // 1st check
    getSpecificNumber(m, res, nums, 8, 'g');
    getSpecificNumber(m, res, nums, 6, 'x');
    getSpecificNumber(m, res, nums, 4, 'u');
    getSpecificNumber(m, res, nums, 2, 'w');
    getSpecificNumber(m, res, nums, 0, 'z');

    // 2nd check
    getSpecificNumber(m, res, nums, 7, 's');
    getSpecificNumber(m, res, nums, 5, 'v');
    getSpecificNumber(m, res, nums, 3, 'h');


    // 3rd check
    getSpecificNumber(m, res, nums, 9, 'i');
    getSpecificNumber(m, res, nums, 1, 'e');

    string digits("");
    for (auto iter = res.begin(); iter != res.end(); ++iter)
    {
        for (int i = 0; i < iter->second; ++i)
            digits += iter->first + '0';
    }

    return digits;
}

void testOriginalDigits()
{
    cout << originalDigits("owoztneoer") << endl;
    cout << originalDigits("fviefuro") << endl;
}

int main()
{
    testOriginalDigits();

    getchar();
    return 0;
}