#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid + k < arr.size() && x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

void printVector(vector<int>& nums) {
    for (auto x: nums) {
        cout << x << ", ";
    }
    cout << endl;
}

void testFindClosestElements() {
    Solution solution;
    vector<int> arr1 {1};
    auto res3 = solution.findClosestElements(arr1, 1, 1);
    printVector(res3);
    vector<int> arr {1,2,3,4,5};
    auto res1 = solution.findClosestElements(arr, 4, 3);
    printVector(res1);
    auto res2 = solution.findClosestElements(arr, 4, -1);
    printVector(res2);
}

int main() {
    testFindClosestElements();
    return 0;
}