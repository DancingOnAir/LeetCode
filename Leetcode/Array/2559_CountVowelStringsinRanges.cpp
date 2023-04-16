#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u'});
        vector<int> preSum {1}, res;
        for (const auto& w : words) {
            preSum.push_back(preSum.back() + (vowel.count(w.front()) && vowel.count(w.back())));
        }

        for (const auto& q : queries) {
            res.push_back(preSum[q[1] + 1] - preSum[q[0]]);
        }
        return res;
    }
};

void print(vector<int>& nums) {
    for (int x : nums) {
        cout << x << ", ";
    }
    cout << endl;
}

void testVowelStrings() {
    Solution solution;
    vector<string> words1 {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries1 {{0,2},{1,4},{1,1}};
    auto res = solution.vowelStrings(words1, queries1);
    print(res);
}

int main() {
    testVowelStrings();
    return 0;
}