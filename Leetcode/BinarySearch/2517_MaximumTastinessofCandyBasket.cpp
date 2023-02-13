#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool check(vector<int>& price, int k, int dist) {
        int cnt = 1, x = price[0];
        for (int p : price) {
            if (p >= x + dist) {
                x = p;
                ++cnt;
            }
        }

        return cnt >= k;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int left = 0, right = (price.back() - price[0]) / (k - 1);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(price, k, mid)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left - 1;
    }
};

void testMaximumTastiness() {
    Solution solution;

    vector<int> price1 {13, 5, 1, 8, 21, 2};
    cout << solution.maximumTastiness(price1, 3) << endl;
    vector<int> price2 {1, 3, 1};
    cout << solution.maximumTastiness(price2, 2) << endl;
    vector<int> price3 {7, 7, 7, 7};
    cout << solution.maximumTastiness(price3, 2) << endl;
}

int main() {
    testMaximumTastiness();
    return 0;
}