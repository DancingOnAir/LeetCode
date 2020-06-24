#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        auto n = arr.size();
        vector<int> res(n, -1);

        for (int i = n - 2; i >= 0; --i) {
            res[i] = max(res[i + 1], arr[i + 1]);
        }

        return res;
    }
};

void printRes(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testReplaceElements() {
    Solution solution;

    vector<int> arr1 {17, 18, 5, 4, 6, 1};
    auto res1 = solution.replaceElements(arr1);
    printRes(res1);
}

int main() {
    testReplaceElements();

    return 0;
}