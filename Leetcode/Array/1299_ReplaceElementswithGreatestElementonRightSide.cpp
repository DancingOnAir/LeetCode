#include <iostream>
#include <vector>

using namespace std;

static const auto fast = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return nullptr;
};

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res(arr.size(), -1);

        for (int i = arr.size() - 2; i >= 0; --i) {
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