#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        vector<string> digits;
        vector<pair<string, string>> letters;
        
        for (auto& log : logs) {
            int i = 0;
            while (log[i] != ' ')
                ++i;
            if (isdigit(log[i + 1])) {
                digits.emplace_back(log);
            }
            else {
                letters.emplace_back(make_pair(log.substr(0, i), log.substr(i + 1)));
            }
        }

        sort(letters.begin(), letters.end(), [](auto& a, auto& b) { return a.second == b.second ? a.first < b.first : a.second < b.second; });
        for (auto& l : letters) {
            res.emplace_back(l.first + " " + l.second);
        }

        for (auto& d : digits) {
            res.emplace_back(d);
        }
        return res;
    }
};

void testReorderLogFiles() {
    Solution solution;

    vector<string> logs1{"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> res1{"let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"};
    assert(solution.reorderLogFiles(logs1) == res1);

    vector<string> logs2{"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    vector<string> res2{"g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"};
    assert(solution.reorderLogFiles(logs2) == res2);
}

int main() {
    testReorderLogFiles();

    return 0;
}