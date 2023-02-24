#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        items.push_back({0, 0});
        sort(items.begin(), items.end());
        for (int i = 1; i < items.size(); ++i) {
            items[i][1] = max(items[i - 1][1], items[i][1]); 
        }

        vector<int> res;
        for (int q : queries) {
            int pos = upper_bound(items.begin(), items.end(), vector<int>{q + 1, 0}) - items.begin();
            res.push_back(items[pos - 1][1]);
        }

        return res;
    }
};

void testMaximumBeauty() {
    Solution solution;
    vector<vector<int>> items1 {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> queries1 {1,2,3,4,5,6};
    auto res1 = solution.maximumBeauty(items1, queries1);
    for (auto& x : res1) {
        cout << x << ", ";
    }
    cout << endl;
}

int main() {
    testMaximumBeauty();
    return 0;
}