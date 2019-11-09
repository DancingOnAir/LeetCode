#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k)
{
    unordered_map<string, int> m;
    for (string& word : words)
        ++m[word];

    map<int, set<string>, greater<int>> count;
    for (auto iter = m.begin(); iter != m.end(); ++iter)
        count[iter->second].emplace(iter->first);

    vector<string> res;
    for (auto iter = count.begin(); iter != count.end(); ++iter)
    {
        for (const string& word : iter->second)
        {
            if (k <= 0)
                break;

            --k;
            res.emplace_back(word);
        }
    }

    return res;
}

void display(const vector<string>& words)
{
    if (words.empty())
        return;

    for (auto& word : words)
        cout << word << ", ";
    cout << endl;
}

void testTopKFrequent()
{
    //vector<string> words1 = { "i", "love", "leetcode", "i", "love", "coding" };
    //int k1 = 2;
    //auto res1 = topKFrequent(words1, k1);
    //display(res1);

    //vector<string> words2 = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
    //int k2 = 4;
    //auto res2 = topKFrequent(words2, k2);
    //display(res2);

    vector<string> words3 = {"aaa","aa","a"};
    int k3 = 3;
    auto res3 = topKFrequent(words3, k3);
    display(res3);
}

int main()
{
    testTopKFrequent();

    getchar();
    return 0;
}