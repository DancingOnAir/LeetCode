#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream iss(s1 + " " + s2);
        string temp;
        unordered_map<string ,int> m;
        while (iss >> temp) {
            ++m[temp];
        }

        vector<string> res;
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second == 1) {
                res.push_back(iter->first);
            }
        }

        return res;
    }
};

void testUncommonFromSentences() {
    Solution solution;

    vector<string> res1{"sweet","sour"};
    assert(solution.uncommonFromSentences("this apple is sweet", "this apple is sour") == res1);
    vector<string> res2{"banana"};
    assert(solution.uncommonFromSentences("apple apple", "banana") == res2);
}

int main() {
    testUncommonFromSentences();

    return 0;
}