#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> diff;
        for (int i = 0; i < reward1.size(); ++i) {
            diff.push_back(reward1[i] - reward2[i]);
        }

        sort(diff.begin(), diff.end());
        return accumulate(reward2.begin(), reward2.end(), 0) + accumulate(diff.end() - k, diff.end(), 0);
    }
};

void testMiceAndCheese() {
    Solution solution;
    vector<int> reward1 {1, 1, 3, 4};
    vector<int> reward2 {4, 4, 1, 1};
    cout << solution.miceAndCheese(reward1, reward2, 2) << endl; 
}

int main() {
    testMiceAndCheese();
    return 0;
}