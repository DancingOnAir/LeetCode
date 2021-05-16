#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });
        vector<string> res;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};

void testStringMatching() {
    Solution solution;

    vector<string> input1{"mass", "as", "hero", "superhero"};
    vector<string> output1{"as", "hero"};
    assert(solution.stringMatching(input1) == output1);
}

int main() {
    testStringMatching();

    return 0;
}