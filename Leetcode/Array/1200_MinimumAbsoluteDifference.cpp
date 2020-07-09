#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int diff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (diff > arr[i + 1] - arr[i])
                diff = arr[i + 1] - arr[i];
        }

        vector<vector<int>> res;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == diff) {
                res.emplace_back(vector<int>{arr[i], arr[i + 1]});
            }
        }

        return res;
    }
};

void printPairs(const vector<vector<int>>& pairs) {
    for (auto& p : pairs) {
        cout << "(" << p[0] << ", " << p[1] << ")" << endl; 
    }
    cout << endl;
}

void testMinimumAbsDifference() {
    Solution solution;

    vector<int> arr1 {4, 2, 1, 3};
    auto res1 = solution.minimumAbsDifference(arr1);
    printPairs(res1);

}

int main() {
    testMinimumAbsDifference();

    return 0;
}