#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getSum(vector<int>& arr, vector<int>& presum, int val) {
        auto iter = lower_bound(arr.begin(), arr.end(), val);
        return presum[iter - arr.begin()] + val * (arr.end() - iter);
    }

    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) {
            return arr[0] < target ? arr[0] : target;
        }

        sort(arr.begin(), arr.end());
        vector<int> presum {0};
        for (int a : arr) {
            presum.emplace_back(presum.back() + a);
        }

        int left = 1, right = arr[n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            getSum(arr, presum, mid) < target ? left = mid + 1 : right = mid;
        }

        return abs(getSum(arr, presum, left) - target) < abs(getSum(arr, presum, left - 1) - target) ? left : left - 1;
    }
};

void testFindBestValue() {
    Solution solution;

    vector<int> arr1 {4, 9, 3};
    int target1 = 10;
    cout << solution.findBestValue(arr1, target1) << endl;

    vector<int> arr2 {2, 3, 5};
    int target2 = 10;
    cout << solution.findBestValue(arr2, target2) << endl;

    vector<int> arr3 {60864, 25176, 27249, 21296, 20204};
    int target3 = 56803;
    cout << solution.findBestValue(arr3, target3) << endl;
}

int main() {
    testFindBestValue();

    return 0;
}