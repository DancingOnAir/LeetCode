#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // https://www.geeksforgeeks.org/count_if-in-c/
        // count_if() function returns the number of elements in a range that satisfy the condition.
        int smaller = count_if(nums.begin(), nums.end(), [&](int x) { return x < target; });
        int equal = count(nums.begin(), nums.end(), target);
        vector<int> res(equal);
        // https://www.geeksforgeeks.org/std-iota-in-cpp/
        iota(res.begin(), res.end(), smaller);
        return res;
    }
};

void printVector(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }

    for (int x : nums) {
        cout << x << ", ";
    }
    cout << endl;
}

void testTargetIndices() {
    Solution solution;
    vector<int> nums {1,2,5,2,3};
    auto res1 = solution.targetIndices(nums, 2);
    printVector(res1);
    auto res2 = solution.targetIndices(nums, 3);
    printVector(res2);
    auto res3 = solution.targetIndices(nums, 5);
    printVector(res3);

}

int main() {
    testTargetIndices();
    return 0;
}