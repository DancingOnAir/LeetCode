#pragma once
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<string> printVertically(string s)
    {
        vector<string> res;
        if (s.empty())
            return res;

        istringstream iss(s);
        string temp;
        vector<string> words;
        size_t maxLen = 0;

        while (iss >> temp)
        {
            words.emplace_back(temp);
            maxLen = maxLen > temp.size() ? maxLen : temp.size();
        }

        for (int i = 0; i < maxLen; ++i)
        {
            temp = "";
            for (int j = 0; j < words.size(); ++j)
            {
                temp += words[j].size() >= i + 1 ? words[j][i] : ' ';
            }

            int pos = temp.find_last_not_of(' ');
            res.emplace_back(temp.substr(0, pos + 1));
        }

        return res;
    }
};