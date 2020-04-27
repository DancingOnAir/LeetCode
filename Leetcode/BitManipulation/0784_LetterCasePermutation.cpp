#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(string& s, int i, vector<string>& res) {
        if (i == s.size()) {
            res.emplace_back(s);
            return;
        }

        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            s[i] ^= 1 << 5;

            backtrack(s, i + 1, res);
            s[i] ^= 1 << 5;
        }
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }

    vector<string> letterCasePermutation1(string S) {
        if (S.empty())
            return vector<string>();

        vector<string> res = {""};
        
        for (int i = 0; i < S.size(); ++i) {
            int n = res.size();
            if (isalpha(S[i])) {
                for (int j = 0; j < n ; ++j) {
                    res.emplace_back(res[j]);
                    res[j] += tolower(S[i]);
                    res[j + n] += toupper(S[i]);
                }
            }
            else {
                for (int j = 0; j < n ; ++j) {
                    res[j] += S[i];
                }
            }
        }

        return res;
    }
};

void printRes(vector<string>& strs) {
    if (strs.empty())
        return;

    for (string& str : strs) {
        cout << str << ", ";
    }

    cout << endl;
}

void testLetterCasePermutation() {
    Solution solution;

    string S1= "a1b2";
    auto res1 = solution.letterCasePermutation(S1);
    printRes(res1);

    string S2= "3z4";
    auto res2 = solution.letterCasePermutation(S2);
    printRes(res2);

    string S3= "12345";
    auto res3 = solution.letterCasePermutation(S3);
    printRes(res3);
}

int main() {
    testLetterCasePermutation();

    return 0;
}