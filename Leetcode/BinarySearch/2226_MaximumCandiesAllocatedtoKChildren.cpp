#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(candies.begin(), candies.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long cur = 0;
            for (int x : candies) {
                cur += (long long)x / mid;
            }

            if (cur >= k) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left - 1;
    }
};

void testMaximumCandies() {
    Solution solution;
    vector<int> candies1 {5,8,6};
    cout << solution.maximumCandies(candies1, 3) << endl;
    vector<int> candies2 {2, 5};
    cout << solution.maximumCandies(candies2, 11) << endl;
}

int main() {
    testMaximumCandies();
    return 0;
}