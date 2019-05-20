#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestPalindromeSubseq(string s)
{
    if (s.empty())
        return 0;

    int res = 0;
    return res;
}

void testLongestPalindromeSubseq()
{
    string s1 = "bbbab";
    cout << longestPalindromeSubseq(s1) << endl;

    string s2 = "cbbd";
    cout << longestPalindromeSubseq(s2) << endl;
}


int main()
{
    testLongestPalindromeSubseq();
    getchar();
    return 0;
}