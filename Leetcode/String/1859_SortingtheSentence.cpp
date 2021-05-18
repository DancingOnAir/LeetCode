#include <string>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        stringstream words(s);
        string word;
        vector<pair<int, string>> memo;

        while (words >> word) {
            auto n = word.size();
            memo.push_back(make_pair((word[n - 1] - '0'), word.substr(0, n - 1)));
        }

        sort(memo.begin(), memo.end());

        string res;
        for (int i = 0; i < memo.size(); ++i) {
            res += memo[i].second;
            if (i != memo.size() - 1) {
                res += " ";
            }
        }
        return res;
    }

    string sortSentence1(string s) {
        map<int, string> m;
        string cur;

        for (char c : s) {
            if (isdigit(c)) {
                m[c - '0'] = cur;
                cur = "";
            }
            else if (isalpha(c)) {
                cur += c;
            }
        }

        string res;
        for (auto& i : m) {
            res += i.second + " ";
        }
        res.pop_back();
        return res;
     }
};

void testSortSentence() {
    Solution solution;
    assert(solution.sortSentence("is2 sentence4 This1 a3") == "This is a sentence");
    assert(solution.sortSentence("Myself2 Me1 I4 and3") == "Me Myself and I");
}

int main() {
    testSortSentence();

    return 0;
}

