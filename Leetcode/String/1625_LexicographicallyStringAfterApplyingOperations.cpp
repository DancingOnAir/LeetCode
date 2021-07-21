#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;
class Solution {
private:
    string add(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            char& c = s[i];
            c = '0' + (c - '0' + a) % 10;
        }

        return s;
    }

    string rotate(string s, int b) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());

        return s;
    }

    void dfs(string s, int a, int b, string& smallest, unordered_set<string>& seen) {
        if (!seen.count(s)) {
            seen.insert(s);
            smallest = min(smallest, s);

            dfs(add(s, a), a, b, smallest, seen);
            dfs(rotate(s, b), a, b, smallest, seen);
        }
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> seen;
        string res = s;
        dfs(s, a, b, res, seen);

        return res;
    }
};

void testFindLexSmallestString() {
    Solution solution;

    assert(solution.findLexSmallestString("5525", 9, 2) == "2050");
    assert(solution.findLexSmallestString("74", 5, 1) == "24");
    assert(solution.findLexSmallestString("0011", 4, 2) == "0011");
    assert(solution.findLexSmallestString("43987654", 7, 3) == "00553311");
}

int main() {
    testFindLexSmallestString();

    return 0;
}