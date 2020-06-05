#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string helper(string& lhs, string& rhs) {
        vector<int> v1(26);
        for (char c : lhs) {
            v1[c - 'a']++;
        }

        string res;
        for (char c : rhs) {
            if (v1[c - 'a']) {
                v1[c - 'a']--;
                res += c;
            }
        }

        return res;
    }

    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        if (n < 2)
            return A;

        string tempStr = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i].empty())
                return vector<string>();
                
            tempStr = helper(tempStr, A[i]);
        }

        vector<string> res;
        for (char c : tempStr) {
            string str;
            res.emplace_back(str + c);
        }

        return res;
    }
};

void printStrings(const vector<string>& strs) {
    for (auto& str : strs) {
        cout << str << ", ";
    }

    cout << endl;
}

void testCommonChars() {
    Solution solution;
    vector<string> A1 {"bella", "label", "roller"};
    auto res1 = solution.commonChars(A1);
    printStrings(res1);

    vector<string> A2 {"cool", "lock", "cook"};
    auto res2 = solution.commonChars(A2);
    printStrings(res2);
}

int main() {
    testCommonChars();

    return 0;
}