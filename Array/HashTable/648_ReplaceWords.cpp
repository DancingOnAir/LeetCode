#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

string replaceWords(vector<string>& dict, string sentence)
{
    unordered_map<char, vector<string>> m;
    for (auto& d : dict)
        m[d[0]].emplace_back(d);

    istringstream iss(sentence);
    string tmp;
    string res;
    while (iss >> tmp)
    {
        if (m.count(tmp[0]))
        {
            int i = 0;
            for (i = 0; i < m[tmp[0]].size(); ++i)
            {
                if (m[tmp[0]][i] == tmp.substr(0, m[tmp[0]][i].size()))
                {
                    res += ' ' + m[tmp[0]][i];
                    break;
                }
                
            }

            if (i >= m[tmp[0]].size())
                res += ' ' + tmp;
        }
        else
            res += ' ' + tmp;
    }

    return res.substr(1);
}

void testReplaceWords()
{
    vector<string> dict1 = { "cat", "bat", "rat" };
    string sentence1 = "the cattle was rattled by the battery";
    string res1 = replaceWords(dict1, sentence1);
    cout << res1 << endl;
}

int main()
{
    testReplaceWords();

    getchar();
    return 0;
}