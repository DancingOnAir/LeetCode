#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = arr.size();
        if (n < k)
            return 0;

        int res = 0, sum = 0, target = threshold * k;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];

            if (i >= k)
                sum -= arr[i - k];
            if (i >= k - 1 && sum >= target)
                ++res;
        }

        return res;
    }
};

void testNumOfSubarrays() {
    Solution solution;

    vector<int> arr1 = {2, 2, 2, 2, 5, 5, 5, 8};
    int k1 = 3, threshold1 = 4;
    cout << solution.numOfSubarrays(arr1, k1, threshold1) << endl;

    vector<int> arr2 = {1, 1, 1, 1, 1};
    int k2 = 1, threshold2 = 0;
    cout << solution.numOfSubarrays(arr2, k2, threshold2) << endl;

    vector<int> arr3 = {11,13,17,23,29,31,7,5,2,3};
    int k3 = 3, threshold3 = 5;
    cout << solution.numOfSubarrays(arr3, k3, threshold3) << endl;

    vector<int> arr4 = {7,7,7,7,7,7,7};
    int k4 = 7, threshold4 = 7;
    cout << solution.numOfSubarrays(arr4, k4, threshold4) << endl;

    vector<int> arr5 = {4,4,4,4};
    int k5 = 4, threshold5 = 1;
    cout << solution.numOfSubarrays(arr5, k5, threshold5) << endl;
}

int main() {
    testNumOfSubarrays();

    return 0;
}