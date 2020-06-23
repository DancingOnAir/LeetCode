#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;

        vector<int> counts(100);
        for (auto& d: dominoes) {
            int key = (d[0] < d[1])? d[0] * 10 + d[1] : d[1] * 10 + d[0];
            res += counts[key];
            counts[key]++;
        }

        return res;
    }

    int numEquivDominoPairs2(vector<vector<int>>& dominoes) {
        int res = 0;
        map<vector<int>, int> counts;
        for (int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }

            counts[dominoes[i]]++;
        }

        for (auto& count : counts) {
            if (count.second > 1)
                res += (count.second - 1) * count.second / 2;
        }

        return res;
    }

    // brute force 
    int numEquivDominoPairs1(vector<vector<int>>& dominoes) {
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