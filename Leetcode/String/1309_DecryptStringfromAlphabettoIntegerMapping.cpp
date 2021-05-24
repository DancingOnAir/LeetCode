#include <string>

using namespace std;
class Solution {
    void replaceString(const string& pat, const string& rep, string& text) {
        auto i = 0;
        while ((i = text.find(pat, i)) != string::npos) {
            text.replace(i, pat.size(), rep);
            i += rep.size();
        }
    }

public:
    string freqAlphabets(string s) {
        for (int i = 26; i > 0; --i) {
            string pat = to_string(i);

            if (i > 9) {
                pat += "#";
            }

            replaceString(pat, string(1, 'a' + i - 1), s);
        }

        return s;
    }
};

void testFreqAlphabets() {
    Solution solution;
    assert(solution.freqAlphabets("10#11#12") == "jkab");
    assert(solution.freqAlphabets("1326#") == "acz");
    assert(solution.freqAlphabets("25#") == "y");
    assert(solution.freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#") == "abcdefghijklmnopqrstuvwxyz");
}

int main() {
    testFreqAlphabets();
    return 0;
}