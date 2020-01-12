#include <iostream>
#include "0211_AddandSearchWord.h"

void test()
{
    WordDictionary wordDictionary;

    //wordDictionary.addWord("bad");
    //wordDictionary.addWord("dad");
    //wordDictionary.addWord("mad");

    //cout << (wordDictionary.search("pad") ? "True" : "False") << endl;
    //cout << (wordDictionary.search("bad") ? "True" : "False") << endl;
    //cout << (wordDictionary.search(".ad") ? "True" : "False") << endl;
    //cout << (wordDictionary.search("b..") ? "True" : "False") << endl;

    wordDictionary.addWord("a");
    wordDictionary.addWord("a");

    cout << (wordDictionary.search("a.") ? "True" : "False") << endl;
    cout << (wordDictionary.search(".a") ? "True" : "False") << endl;
}

int main()
{
    test();

    getchar();
    return 0;
}
