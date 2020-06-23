#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    # brute force 
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        for (auto i = 0; i < dominoes.size() - 1; ++i) {
            for (auto j = i + 1; j < dominoes.size(); ++j) {
                if ((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) ||
                (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])) {
                    ++res;
                }
            }
        }

        return res;
    }
};

void testNumEquivDominoPairs() {
    Solution solution;

    vector<vector<int>> dominoes1 = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
    cout << solution.numEquivDominoPairs(dominoes1) << endl;
}

int main() {
    testNumEquivDominoPairs();

    return 0;
}