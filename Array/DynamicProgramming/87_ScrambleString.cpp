#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool isScramble(string s1, string s2)
{
    if (s1 == s2)
        return true;
    
    int l1 = s1.size();
    int l2 = s2.size();

    vector<int> count(26);

    for (int i = 0; i < l1; ++i)
    {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (count[i] != 0)
            return false;
    }

    for (int i = 1; i < l1; ++i)
    {
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            return true;

        if (isScramble(s1.substr(0, i), s2.substr(l1 - i)) && isScramble(s1.substr(i), s2.substr(0, l1 - i)))
            return true;
    }

    return false;
}

void testIsScramble()
{
    string s1 = "great";
    string s2 = "rgeat";

    cout << (isScramble(s1, s2)?"true":"false") << endl;
}

int main()
{
    testIsScramble();

    getchar();
    return 0;
}