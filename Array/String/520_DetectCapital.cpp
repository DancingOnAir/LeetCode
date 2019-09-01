#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool detectCapitalUse2(string word)
{
    for (int i = 1; i < word.size(); ++i)
    {
        if (isupper(word[1]) != isupper(word[i]) ||
            islower(word[0]) && isupper(word[i]))
            return false;
    }

    return true;
}

bool detectCapitalUse(string word)
{
    return regex_match(word, regex("[A-Z]+|[a-z]+|[A-Z][a-z]*"));
}

void testDetectCapitalUse()
{
    string word1 = "USA";
    cout << (detectCapitalUse(word1) ? "True" : "False") << endl;

    //string word2 = "FlaG";
    //cout << (detectCapitalUse(word2) ? "True" : "False") << endl;
}

int main()
{
    testDetectCapitalUse();

    getchar();
    return 0;
}