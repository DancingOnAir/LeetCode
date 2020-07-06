#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int> ps(1);
        int mask = 0;

        for (char c : s) {
            ps.emplace_back(mask ^= 1 << (c - 'a'));
        }

        vector<bool> res;
        for (auto& q : queries) {
            // int odds = __builtin_popcount(ps[q[1] + 1] ^ ps[q[0]]);
            int odds = bitset<26>(ps[q[1] + 1] ^ ps[q[0]]).count();
            res.emplace_back(q[2] >= odds / 2);
        }

        return res;
    }
};

void printRes(const vector<bool>& res) {
    for (bool r : res) {
        cout << (r ? "True" : "False") << ", ";
    }
    cout << endl;
}

void testCanMakePaliQueries() {
    Solution solution;

    vector<vector<int>> queries1 {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
    string s1 = "abcda";
    auto res1 = solution.canMakePaliQueries(s1, queries1);
    printRes(res1);
}

int main() {
    testCanMakePaliQueries();

    return 0;
}