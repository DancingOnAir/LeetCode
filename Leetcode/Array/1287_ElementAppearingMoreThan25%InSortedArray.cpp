#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        auto n = arr.size();

        unordered_map<int, int> counts;
        for (auto i = 0; i < n; ++i) {
            counts[arr[i]]++;
            if (counts[arr[i]] > n / 4)
                return arr[i];
        }

        return -1;
    }
};

void testFindSpecialInteger() {
    Solution solution;

    vector<int> arr1 {1, 2, 2, 6, 6, 6, 6, 7, 10};
    cout << solution.findSpecialInteger(arr1) << endl;
}

int main() {
    testFindSpecialInteger();

    return 0;
}