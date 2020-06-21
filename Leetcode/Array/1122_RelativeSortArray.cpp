#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr2.size(); ++i) {
            m[arr2[i]] = i;
        }

        vector<int> res;
        vector<int> resNotInArr2;

        for (int i = 0; i < arr1.size(); ++i) {
            if (m.count(arr1[i])) {
                res.emplace_back(arr1[i]);
            }
            else {
                resNotInArr2.emplace_back(arr1[i]);
            }
        }
        
        sort(res.begin(), res.end(), [&](const int lhs, const int rhs) { return m[lhs] < m[rhs]; });
        sort(resNotInArr2.begin(), resNotInArr2.end());
        res.insert(res.end(), resNotInArr2.begin(), resNotInArr2.end());
        return res;
    }
};

void printRes(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testRelativeSortArray(){
    Solution solution;

    vector<int> arr1 {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 {2, 1, 4, 3, 9, 6};
    auto res = solution.relativeSortArray(arr1, arr2);
    printRes(res);
}

int main() {
    testRelativeSortArray();

    return 0;
}