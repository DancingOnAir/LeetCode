#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    vector<int> m(128);
    for (char c : magazine)
        ++m[c];

    for (int i = 0; i < ransomNote.size(); ++i)
    {
        if (m[ransomNote[i]] <= 0)
            return false;

        --m[ransomNote[i]];
    }

    return true;
}

void testCanConstruct()
{
    cout << (canConstruct("a", "b") ? "True" : "False") << endl;
    cout << (canConstruct("aa", "ab") ? "True" : "False") << endl;
    cout << (canConstruct("aa", "aab") ? "True" : "False") << endl;
}

int main()
{
    testCanConstruct();

    getchar();
    return 0;
}
