#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<string> topKFrequent2(vector<string>& words, int k)
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

vector<string> topKFrequent(vector<string>& words, int k)
{
    unordered_map<string, int> m;
    for (auto& word : words)
        ++m[word];

    auto comp = [&](pair<string, int>& lhs, pair<string, int>& rhs) 
    {
        return lhs.second > rhs.second || lhs.second == rhs.second && lhs.first < rhs.first;
    };

    typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> my_prioprity_queue_t;
    my_prioprity_queue_t pq(comp);

    for (auto w : m)
    {
        pq.emplace(w.first, w.second);
        if (pq.size() > k)
            pq.pop();
    }

    vector<string> res;
    while (!pq.empty())
    {
        res.insert(res.begin(), pq.top().first);
        pq.pop();
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
    vector<string> words1 = { "i", "love", "leetcode", "i", "love", "coding" };
    int k1 = 3;
    auto res1 = topKFrequent(words1, k1);
    display(res1);

    vector<string> words2 = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
    int k2 = 4;
    auto res2 = topKFrequent(words2, k2);
    display(res2);

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