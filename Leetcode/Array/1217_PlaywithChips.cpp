#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0;
        for (int chip : chips) {
            if (chip & 1)
                ++odd;
        }

        return min(odd, (int)chips.size() - odd);
    }

    int minCostToMoveChips1(vector<int>& chips) {
        map<int, int> m;

        for (int chip : chips) {
            m[chip]++;
        }

        int minPos = -1, sum = 0;
        for (auto& iter : m) {
            if (minPos == -1) {
                minPos = iter.first;
            }

            if (((iter.first - minPos) & 1) == 0) {
                sum += iter.second;
            }
        }

        return min(sum, (int)chips.size() - sum);
    }
};

void testMinCostToMoveChips() {
    Solution solution;

    vector<int> chips1 = {1, 2, 3};
    cout << solution.minCostToMoveChips(chips1) << endl;

    vector<int> chips2 = {2, 2, 2, 3, 3};
    cout << solution.minCostToMoveChips(chips2) << endl;

    vector<int> chips3 = {1, 2, 2, 2, 2};
    cout << solution.minCostToMoveChips(chips3) << endl;

}

int main() {
    testMinCostToMoveChips();

    return 0;
}