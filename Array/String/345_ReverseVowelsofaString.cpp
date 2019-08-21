#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string reverseVowels(string s)
{
    unordered_set<char> t{ 'a', 'e', 'i', 'o', 'u' };
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j)
    {

        while (i < n && t.find(tolower(s[i])) == t.end())
            ++i;

        while (j >= 0 && t.find(tolower(s[j])) == t.end())
            --j;

        if (i < j)
        {
            swap(s[i], s[j]);
            ++i;
            --j;
        }
    }

    return s;
}

void testReverseVowels()
{
    
    cout << reverseVowels(",; W;:GlG:;l ;,") << endl;
    cout << reverseVowels("OE") << endl;
    cout << reverseVowels("hello") << endl;
    cout << reverseVowels("leetcode") << endl;
}

int main()
{
    testReverseVowels();

    getchar();
    return 0;
}