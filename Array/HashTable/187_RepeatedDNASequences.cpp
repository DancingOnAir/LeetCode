#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    if (s.size() < 11)
        return vector<string>();

    vector<string> res;
    unordered_map<string, int> m;
    for (int i = 0; i <= s.size() - 10; i++)
    {
        if (m[s.substr(i, 10)]++ == 1)
            res.emplace_back(s.substr(i, 10));
    }

    return res;
}

void display(vector<string>& v)
{
    for (string& s : v)
        cout << s << ", ";
    cout << endl;
}

void testFindRepeatedDnaSequences()
{
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto res1 = findRepeatedDnaSequences(s1);
    display(res1);

    string s2 = "AAAAAAAAAAAA";
    auto res2 = findRepeatedDnaSequences(s2);
    display(res2);
}

int main()
{
    testFindRepeatedDnaSequences();

    getchar();
    return 0;
}