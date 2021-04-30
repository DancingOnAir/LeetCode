#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;
using std::stable_sort;

class Solution {
public:
    string arrangeWords(string text) {
        text[0] += ('a' - 'A');

        vector<string> words;
        stringstream ss(text);
        string word;

        while (ss >> word) {
            words.emplace_back(word);
        }

        stable_sort(words.begin(), words.end(), [](const string& s1, const string& s2) -> bool { return s1.size() < s2.size(); });
        string res = "";
        for (auto& w : words) {
            res += w + " ";
        }
        res.pop_back();
        res[0] -= ('a' - 'A');

        return res;
    }
};

void testArrangeWords() {
    Solution solution;

    assert(solution.arrangeWords("Leetcode is cool") == "Is cool leetcode");
    assert(solution.arrangeWords("Keep calm and code on") == "On and keep calm code");
    assert(solution.arrangeWords("To be or not to be") == "To be or to be not");
    cout << "Pass Testing" << endl;
}


int main() {
    testArrangeWords();

    return 0;
}