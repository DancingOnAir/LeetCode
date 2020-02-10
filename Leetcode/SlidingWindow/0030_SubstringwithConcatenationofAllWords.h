#pragma once
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> res;
        if (s.empty() || words.empty() || words[0].empty())
            return res;

        int sizeOfWord = words[0].size();
        if (s.size() < sizeOfWord)
            return res;

        for (int i = 0; i < sizeOfWord; ++i)
        {
            int left = i, right = i, counter = words.size();;
            unordered_map<string, int> m;
            for (auto& word : words)
                m[word]++;

            while (right < s.size() - sizeOfWord + 1)
            {

                if (m[s.substr(right, sizeOfWord)]-- > 0)
                    --counter;

                right += sizeOfWord;

                while (counter == 0)
                {
                    if (right - left == words.size() * sizeOfWord)
                        res.emplace_back(left);

                    if (m[s.substr(left, sizeOfWord)]++ == 0)
                        ++counter;

                    left += sizeOfWord;
                }
            }
        }


        return res;
    }
};