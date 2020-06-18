#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        if (n < 2)
            return;
        
        vector<int> res;
        for (int i = 0, j = 0; i < n && j < n; ++i, ++j) {
            if (arr[i]) {
                res.emplace_back(arr[i]);
            }
            else {
                res.emplace_back(0);
                if (j < n - 1) {
                    res.emplace_back(0);
                    ++j;
                }
            }
        }
        
        arr = res;
    }
};

void printRes(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testDuplicateZeros() {
    Solution solution;

    vector<int> arr1 {1, 0, 2, 3, 0, 4, 5, 0};
    solution.duplicateZeros(arr1);
    printRes(arr1);

    vector<int> arr2 {1, 2, 3};
    solution.duplicateZeros(arr2);
    printRes(arr2);
}

int main() {
    testDuplicateZeros();

    return 0;
}