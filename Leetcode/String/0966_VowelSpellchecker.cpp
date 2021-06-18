#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
private:
    string toLow(string s) {
        for (char& c : s) {
            c = tolower(c);
        }

        return s;
    }

    string toDevowel(string s) {
        s = toLow(s);
        for (char& c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }

        return s;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caps, vowels;
        for (auto w : wordlist) {
            string lower = toLow(w);
            if (!caps.count(lower))
                caps[lower] = w;

            string devowel = toDevowel(w);
            if (!vowels.count(devowel))
                vowels[devowel] = w;
        }

        for (int i = 0; i < queries.size(); ++i) {
            if (words.count(queries[i]))
                continue;
            
            string lower = toLow(queries[i]);
            string devowel = toDevowel(queries[i]);
            if (caps.count(lower))
                queries[i] = caps[lower];
            else if (vowels.count(devowel))
                queries[i] = vowels[devowel];
            else
                queries[i] = "";
        }

        return queries;
    }
};

void testSpellChecker() {
    Solution solution;

    vector<string> wordlist1{"KiTe","kite","hare","Hare"};
    vector<string> queries1{"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    vector<string> res1{"kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"};
    assert(solution.spellchecker(wordlist1, queries1) == res1);

    vector<string> wordlist2{"yellow"};
    vector<string> queries2{"YellOw"};
    vector<string> res2{"yellow"};
    assert(solution.spellchecker(wordlist2, queries2) == res2);
}

int main() {
    testSpellChecker();

    return 0;
}