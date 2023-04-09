#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> seen;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                seen[0] = {i, i};
                continue;
            }

            long long v = 0;
            for (int j = i; j < min(i + 30, (int)s.size()); ++j) {
                v = (v << 1) + (s[j] - '0');
                seen[v] = {i, j};
            }
        }

        vector<vector<int>> res;
        for (auto& q : queries) {
            if (seen.find(q[0] ^ q[1]) == seen.end()) {
                res.push_back({-1, -1});
            }
            else {
                res.push_back(seen[q[0] ^ q[1]]);
            }
        }

        return res;
    }
};

void print(vector<vector<int>>& matrix) {
    for (auto& r : matrix) {
        cout << "{";
        for (auto& c : r) {
            cout << c << ", ";
        }
        cout << "}, ";
    }
}


void testSubstringXorQueries() {
    Solution solution;

    vector<vector<int>> q1 {{0,5},{1,2}};
    auto res1 = solution.substringXorQueries("101101", q1);
    print(res1);

    vector<vector<int>> q2 {{12,8}};
    auto res2 = solution.substringXorQueries("0101", q2);
    print(res2);
}

int main() {
    testSubstringXorQueries();
    return 0;
}